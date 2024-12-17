/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:04:24 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 09:28:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_cmd_nt_found(t_cmd *cmd, char **env_2d, char **path_spl, char *path)
{
	ft_error_writer(cmd->arg[0], " :command not found\n");
	fflush(stderr);
	ft_free_env2d_pathspl(env_2d, path_spl, path);
}

char	*get_path_for_exeve(char *cmd_arg, char *path, char **path_spl)
{
	if (path)
		free(path);
	if (ft_strchr(cmd_arg, '/'))
		path = ft_strdup(cmd_arg);
	else
		path = ft_test_access(path_spl, cmd_arg);
	return (path);
}

void	close_herdocc_fd(t_file *rfile)
{
	while (rfile)
	{
		if (rfile->type == HEREDOC)
		{
			// printf("rfile->fd = %s\n",rfile->content);
			close(rfile->fd);
		}	
		rfile = rfile->next;
	}
}
