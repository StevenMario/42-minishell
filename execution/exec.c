/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/15 07:32:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_exec(t_cmd *cmd, t_env *env)
{
	pid_t	pid;
	// int	status;
	// int	cmd_process;

	pid = fork();
	// cmd_process = check_cmd_process(cmd);
	// if (pid == 0 && cmd_process == 1)
	// 	exit (0);
	// printf("pid = %d\n",pid);
	if (pid == 0)
		exec_extern_cmd(env, cmd);
	else 
		return (1);
	return (0);
	
}