/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:07:29 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/05 13:39:19 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->arg[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "export") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "env") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd->arg[0], "exit") == 0)
		return (1);
	else
		return (-1);
}

int	ft_exec_if_builtins(t_cmd *cmd, t_data	*mish, t_env *env)
{
	if (ft_strcmp(cmd->arg[0], "cd") == 0)
	{
		mish->exit_status = ft_cd(cmd, env);
		return (1);
	}
	else if (ft_strcmp(cmd->arg[0], "export") == 0)
	{
		mish->exit_status = ft_export(mish);
		return (1);
	}
	else if (ft_strcmp(cmd->arg[0], "unset") == 0)
	{
		mish->exit_status = ft_unset(cmd, env);
		return (1);
	}
	else if (ft_strcmp(cmd->arg[0], "pwd") == 0)
		ft_pwd(env);
	else if (ft_strcmp(cmd->arg[0], "env") == 0)
		ft_env(cmd, env);
	else if (ft_strcmp(cmd->arg[0], "echo") == 0)
		ft_echo(cmd->arg);
	else if (ft_strcmp(cmd->arg[0], "exit") == 0)
		mish->exit_status = ft_exit(mish, cmd);
	return (0);
}
