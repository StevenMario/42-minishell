/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:04:24 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 15:35:19 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_cmd_nt_found(t_cmd *cmd, char **env_2d, char **path_spl, char *path)
{
	(void)env_2d;
	(void)path_spl;
	(void)path;
	ft_error_writer(cmd->arg[0], " :command not found\n");
	fflush(stderr);
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
			if (rfile->fd)
				close(rfile->fd);
		}
		rfile = rfile->next;
	}
}

void	ft_pre_execv(t_cmd *cmd, t_data *mish, int status, t_env *env)
{
	rl_clear_history();
	handling_signal_child();
	if (cmd->rfile != NULL)
		ft_browse_redir(cmd, mish);
	clear_fd(mish);
	status = exec_extern_cmd(env, cmd, mish);
	clear_data(mish);
	exit(status);
}

void	ft_exit_w_st(t_data *mish, int status)
{
	clear_data(mish);
	exit(status);
}
