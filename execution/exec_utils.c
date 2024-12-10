/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:11:23 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/10 16:05:10 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_restore_std(int backup[2])
{
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
}

void	close_fds(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	dup_std(int r_fd[2])
{
	r_fd[0] = dup(STDIN_FILENO);
	r_fd[1] = dup(STDOUT_FILENO);
}

int	ft_count_cmd(t_data *mish)
{
	int		count;
	t_cmd	*cmd;

	count = 0;
	cmd = mish->cmd;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

int	get_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
	{
		exit_status = WEXITSTATUS(exit_status);
	}
	else if (WIFSIGNALED(exit_status))
	{
		exit_status = WTERMSIG(exit_status) + 128;
		write(2, "\n", 2);
	}
	return (exit_status);
}
