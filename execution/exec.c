/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/09 13:20:30 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	handling_signal_parents(void)
{
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
}
static void	handling_signal_child(void)
{
	// struct sigaction action;

	// memset(&action, 0, sizeof(action));
	// action.sa_handler = signal_handler;
	// sigemptyset(&action.sa_mask);
	// action.sa_flags = 0;
	// sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT,SIG_DFL);
	signal(SIGINT,SIG_DFL);
	// signal(SIGQUIT,SIG_DFL);
}

int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env)
{
	if (ft_is_builtin(cmd) == 1)
		exec_redir_builtin(mish, cmd, env);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		handling_signal_parents();
		if (cmd->pid == 0)
		{
			handling_signal_child();
			if (cmd->rfile != NULL)
				ft_browse_redir(cmd);
			exec_extern_cmd(env, cmd);
			clear_data(mish);
			rl_clear_history();
			exit(EXIT_SUCCESS);
		}
		waitpid(cmd->pid, &mish->exit_status, 0);
		mish->exit_status = get_exit_status(mish->exit_status);
	}
	return (mish->exit_status);
}

void	set_pipe_cmd(t_data *mish, t_cmd *cmd, int backup[2]) // link_cmd
{
	int	fds[2];

	if (pipe(fds) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cmd->pid = fork();
	handling_signal_parents();
	if (cmd->pid == 0)
	{
		handling_signal_child();
		close_fds(backup);
		if (cmd->next != NULL)
			dup2(fds[1], STDOUT_FILENO);
		close_fds(fds);
		exec_simple_cmd(mish, cmd, mish->e_lst);
		clear_data(mish);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close_fds(fds);
	}
}

void	clear_data_without_env(t_data *data)
{
	if (data)
	{
		if (data->cmd)
			ft_lstclear_cmd(&data->cmd);
		if (data->token)
			ft_lstclear_token(&data->token);
	}
}

void fill_new_cmd_arg(t_cmd *cmd,char *simple_cmd)
{
	char **str;
	int len;
	int i;
	(void)cmd;

	i = -1;
	str = NULL;
	len = 0;
	str = ft_split(simple_cmd,' ');
	if (cmd->arg)
		ft_free_str(cmd->arg);
	while (str[len])
		len++;
	cmd->arg = malloc(sizeof(char *) * (len + 1));
	cmd->arg[len] = NULL;
	while (str[++i])
	{
		cmd->arg[i] = ft_strdup(str[i]);
	}
	ft_free_str(str);
}

void check_double_cmd(t_cmd *cmd)
{
	char *simple_cmd;
	int i;

	i = 1;
	if (ft_count_char_in_str(cmd->arg[0],' ') > 0)
	{
		simple_cmd = ft_strdup(cmd->arg[0]);
		while (cmd->arg[i])
		{
			simple_cmd = ft_strjoin(simple_cmd," ");
			simple_cmd = ft_strjoin(simple_cmd,cmd->arg[i]);
			i++;
		}
		fill_new_cmd_arg(cmd,simple_cmd);
		free(simple_cmd);
		// printf("simple_cmd  = %s\n",simple_cmd);
	}
}

void	piping_cmd(t_data *mish, int backup[2]) //pipeline
{
	t_cmd	*cmd;
	// char	*double_cmd;
	int		count;

	count = ft_count_cmd(mish);
	cmd = mish->cmd;
	if (count == 1)
	{
		check_double_cmd(cmd);
		// print_cmd(cmd);
		exec_simple_cmd(mish, cmd, mish->e_lst);
		return ;
	}
	dup_std(backup);
	while (cmd)
	{
		check_double_cmd(cmd);
		set_pipe_cmd(mish, cmd, backup);
		cmd = cmd->next;
	}
	cmd = mish->cmd;
	while (cmd->next != NULL)
	{
		// if (cmd->next == NULL)
		// 	waitpid(cmd->pid, NULL, 0);
		// else
		waitpid(cmd->pid, &mish->exit_status, 0);
		cmd = cmd->next;
	}
	if (WIFEXITED(mish->exit_status))
	{
	
	}
	else if (WIFSIGNALED(mish->exit_status))
		write(1, "\n", 2);
	waitpid(cmd->pid, &mish->exit_status, 0);
	mish->exit_status = get_exit_status(mish->exit_status);
	ft_restore_std(backup);
	close_fds(backup);
	clear_data_without_env(mish);
}
