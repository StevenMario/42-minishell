/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:11:23 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/11/20 14:25:03 by iarantsoa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_restore_std(int backup[2]);
{
	dup2(STDOUT_FILENO, backup[0]);
	dup2(STDIN_FILENO, backup[1]);
}
void	close_fds(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}
void	dup_std(int r_fd[2]);
{
	r_fd[0] = dup(STDIN_FILENO);
	r_fd[1] = dup(STDOUT_FILENO);
}

int	ft_count_cmd(t_cmd *cmd)
{
	int    count;

    count = 0;
    while (cmd)
    {
        i++;
        cmd = cmd->next;
    }
    return (count);
}

void get_exit_status(t_data *mish)
{
	int wstatus;

	wait(&wstatus);
	if (WIFEXITED(wstatus))
		mish->exit_status = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	    mish->exit_status = WTERMSIG(wstatus);
}