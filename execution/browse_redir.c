/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:06:00 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/18 10:51:58 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

int 	ft_browse_builtins(t_cmd *cmd, t_data *data)
{
	t_file	*redir;

	(void)data;
    redir = cmd->rfile;
	while (redir)
	{
		ft_open_redir(redir);
		if (redir->fd == -1)
		{			
			check_error_redir(redir);
			return (data->exit_status = 1);
		}
		check_type_for_dup2(redir);
		close(redir->fd);
		redir = redir->next;
	}
    return (0);
}

void	ft_browse_redir2(t_cmd *cmd, t_data *data,int fds[2])
{
	t_file	*redir;

	redir = cmd->rfile;
	while (redir)
	{
		ft_open_redir(redir);
		if (redir->fd == -1)
		{			
			check_error_redir(redir);
			close_fds(fds);
			clear_data(data);
			exit(EXIT_FAILURE);
		}
		check_type_for_dup2(redir);
		close(redir->fd);
		redir = redir->next;
	}
}

void	ft_browse_redir(t_cmd *cmd, t_data *data)
{
	t_file	*redir;

	redir = cmd->rfile;
	while (redir)
	{
		ft_open_redir(redir);
		if (redir->fd == -1)
		{
			check_error_redir(redir);
			clear_data(data);
			exit(EXIT_FAILURE);
		}
		check_type_for_dup2(redir);
		close(redir->fd);
		redir = redir->next;
	}
}