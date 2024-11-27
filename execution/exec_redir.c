/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/27 13:08:51 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"
void check_type_for_dup2(t_file *redir)
{
	if (redir->type == TRUNC || redir->type == APPEND)
		dup2(redir->fd, STDOUT_FILENO);
	else
		dup2(redir->fd, STDIN_FILENO);
}
void	ft_setup_redir(t_file *redir)
{
	if (redir->type == TRUNC && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->type == APPEND && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_APPEND | O_WRONLY, 0664);
	else if (redir->type == INPUT)
		redir->fd = open(redir->content, O_RDONLY)
	check_type_for_dup2(redir);
	close(redir->fd);
		
}

int	ft_browse_redir(t_cmd *cmd)
{
	t_file *redir;

	redir = cmd->rfile;
	while (redir)
	{

	}
}