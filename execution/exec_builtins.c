/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:07:29 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/29 12:34:50 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_cmd_process(t_cmd *cmd)
{
	if (ft_strncmp(cmd->arg[0], "cd\0", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd->arg[0], "export\0", 7) == 0)
		return (1);
	else if (ft_strncmp(cmd->arg[0], "unset\0", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd->arg[0], "pwd\0", 4) == 0)
		return (0);
	else if (ft_strncmp(cmd->arg[0], "env\0", 4) == 0)
		return (0);
	else if (ft_strncmp(cmd->arg[0], "echo\0", 6) == 0)
		return (0);
	else
		return (-1);
}
int	ft_exec_if_builtins(t_cmd *cmd, t_data	*mish, t_env *env)
{
	if (ft_strncmp(cmd->arg[0], "cd\0", 3) == 0)
	{
		mish->exit_status = ft_cd(cmd, env);
		return (1);
	}
	else if (ft_strncmp(cmd->arg[0], "export\0", 7) == 0)
	{
		mish->exit_status = ft_export(cmd, env);
		return (1);
	}
	else if (ft_strncmp(cmd->arg[0], "unset\0", 6) == 0)
	{
		mish->exit_status = ft_unset(cmd, env);
		return (1);
	}
	else if (ft_strncmp(cmd->arg[0], "pwd\0", 4) == 0)
		ft_pwd(env);
	else if (ft_strncmp(cmd->arg[0], "env\0", 4) == 0)
		ft_env(cmd, env);
	else if (ft_strncmp(cmd->arg[0], "echo\0", 6) == 0)
		ft_echo(cmd->arg);
	return (0);
}
