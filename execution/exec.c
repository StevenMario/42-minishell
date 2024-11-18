/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/18 08:59:59 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// int	ft_exec(t_cmd *cmd, t_env *env)
// {
// 	pid_t	pid;
// 	// int	status;
// 	// int	cmd_process;

// 	pid = fork();
// 	// cmd_process = check_cmd_process(cmd);
// 	// if (pid == 0 && cmd_process == 1)
// 	// 	exit (0);
// 	// printf("pid = %d\n",pid);
// 	if (pid == 0)
// 		exec_extern_cmd(env, cmd);
// 	else 
// 		return (1);
// 	return (0);
	
// }
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
