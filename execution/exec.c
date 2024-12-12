/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/12 10:18:22 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env)
{
	if (ft_is_builtin(cmd) == 1)
		exec_redir_builtin(mish, cmd, env);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			ft_perror("fork");
		handling_signal_parents();
		if (cmd->pid == 0)
		{
			rl_clear_history();
			handling_signal_child();
			if (cmd->rfile != NULL)
				ft_browse_redir(cmd);
			exec_extern_cmd(env, cmd, mish);
			clear_data(mish);
			exit(mish->exit_status);
		}
		waitpid(cmd->pid, &mish->exit_status, 0);
		mish->exit_status = get_exit_status(mish->exit_status);
	}
	return (mish->exit_status);
}

void	set_pipe_cmd(t_data *mish, t_cmd *cmd, int backup[2])
{
	int	fds[2];
	int	status;

	if (pipe(fds) == -1)
		ft_perror("pipe");
	cmd->pid = fork();
	handling_signal_parents();
	if (cmd->pid == 0)
	{
		close_fds(backup);
		rl_clear_history();
		handling_signal_child();
		if (cmd->next != NULL)
			dup2(fds[1], STDOUT_FILENO);
		close_fds(fds);
		status = exec_simple_cmd(mish, cmd, mish->e_lst);
		clear_data(mish);
		exit(status);
	}
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close_fds(fds);
	}
}

void	fill_new_cmd_arg(t_cmd *cmd, char *simple_cmd)
{
	char	**str;
	int		len;
	int		i;

	(void)cmd;
	i = -1;
	str = NULL;
	len = 0;
	str = ft_split(simple_cmd, ' ');
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

void	check_double_cmd(t_cmd *cmd)
{
	char	*simple_cmd;
	int		i;

	i = 1;
	if (ft_count_char_in_str(cmd->arg[0], ' ') > 0)
	{
		simple_cmd = ft_strdup(cmd->arg[0]);
		while (cmd->arg[i])
		{
			simple_cmd = ft_strjoin(simple_cmd, " ");
			simple_cmd = ft_strjoin(simple_cmd, cmd->arg[i]);
			i++;
		}
		fill_new_cmd_arg(cmd, simple_cmd);
		free(simple_cmd);
	}
}

void	piping_cmd(t_data *mish, int backup[2])
{
	t_cmd	*cmd;
	int		count;

	cmd = NULL;
	count = ft_count_cmd(mish);
	cmd = mish->cmd;
	if (count == 1)
		return (ft_exec_one_cmd(cmd, mish));
	dup_std(backup);
	while (cmd)
	{
		ft_exec_mltpl_cmd(cmd, mish, backup);
		cmd = cmd->next;
	}
	cmd = mish->cmd;
	while (cmd != NULL)
	{
		waitpid(cmd->pid, &cmd->status, 0);
		cmd->status = get_exit_status(cmd->status);
		if (cmd->next == NULL)
			mish->exit_status = get_exit_status(cmd->status);
		cmd = cmd->next;
	}
	end_of_exec(mish, backup);
}
