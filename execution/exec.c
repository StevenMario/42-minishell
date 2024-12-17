/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 16:35:49 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env, int backup[2])
{
	int	status;

	status = 0;
	close_fds(backup);
	if (ft_is_builtin(cmd) == 1)
		exec_redir_builtin(mish, cmd, env);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			ft_perror("fork");
		handling_signal_parents();
		if (cmd->pid == 0)
			ft_pre_execv(cmd, mish, status, env);
		clear_fd(mish);
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
	if (cmd->rfile != NULL)
		ft_browse_redir(cmd, mish);
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
		status = exec_simple_cmd(mish, cmd, mish->e_lst, backup);
		ft_exit_w_st(mish, status);
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

void	piping_cmd(t_data *mish, int backup[2])
{
	t_cmd	*cmd;
	int		count;

	count = ft_count_cmd(mish);
	cmd = mish->cmd;
	dup_std(backup);
	if (count == 1)
		return (ft_exec_one_cmd(cmd, mish, backup));
	else
		loop_exec_pcmd(backup, mish);
	cmd = mish->cmd;
	while (cmd != NULL)
	{
		if (cmd->pid != 0)
			waitpid(cmd->pid, &cmd->status, 0);
		cmd->status = get_exit_status(cmd->status);
		if (cmd->next == NULL)
			mish->exit_status = get_exit_status(cmd->status);
		cmd = cmd->next;
	}
	end_of_exec(mish, backup);
}
