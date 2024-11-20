/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:11:23 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/11/20 13:50:10 by iarantsoa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void dup_std(int in, int out)
{
	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
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