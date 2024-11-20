/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/20 14:27:30 by iarantsoa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env)
{
	if (ft_is_builtin(cmd) == 1)
	{
		ft_exec_if_builtins(cmd, mish, env);
		return (0);
	}
	else
	{
		cmd->pid = fork();
		if (cmd->pid == 0)
		{
			exec_extern_cmd(env, cmd);
			exit(1);
		}
		wait(0);
	}
	return (0);
}

void	set_pipe_cmd(t_data *mish, int restore_std[2])
{
	int fds[2];
	t_cmd *cmd;

	cmd = mish->cmd;
	dup_std(restore_std);
	if(pipe(fds) == -1)
	{
		perror("pipe");
        exit(EXIT_FAILURE);
	}
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(fd[0], STDOUT_FILENO);
		close_fds(fds);
		close_fds(restore_std);
		exec_simple_cmd(mish, cmd, mish->e_lst);
	}
	else
	{
	    dup2(fd[1], STDIN_FILENO);
	    close_fds(fds);
	    ft_restore_std(restore_std);
	}
}

int piping_cmd(t_data *mish)
{
	t_cmd *cmd;
	int count;

    count = ft_count_cmd(cmd);
	cmd = mish->cmd;
	if (count == 1)
	{
		exec_simple_cmd(mish, cmd, mish->env);
        get_exit_status(mish);
	}
	else
	{
		set_pipe_cmd(mish)
	}
}
