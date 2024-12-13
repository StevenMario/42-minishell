/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:04:24 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 15:20:07 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_cmd_nt_found(t_cmd *cmd, char **env_2d, char **path_spl, char *path)
{
	ft_error_writer(cmd->arg[0], " :command not found\n");
	fflush(stderr);
	ft_free_env2d_pathspl(env_2d, path_spl, path);
}

void	first_check_for_path(t_cmd *cmd, char *path, char **path_spl)
{
	if (ft_strchr(cmd->arg[0], '/'))
			path = ft_strdup(cmd->arg[0]);
	else
		path = ft_test_access(path_spl, cmd->arg[0]);
}