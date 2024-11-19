/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/19 21:45:31 by iarantsoa        ###   ########.fr       */
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

int	ft_fork_cmd(t_data *mish, t_cmd *cmd)
{
	int	fd[2];

	pipe(fd);
	cmd->pid = fork();
	if (cmd->pid == -1)
		perror("fork");
	if (cmd->pid == 0)
	{
		
	}
	
}