/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/27 12:27:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

void	ft_setup_redir(t_file *redir)
{
	if (redir->type == TRUNC && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if ()
	// if TRUNC na APPEND dup stdout
	// if HEREDOC na INPUT dup2 sdin
	//close _fd
		
}

int	ft_browse_redir(t_cmd *cmd)
{
	t_file *redir;

	redir = cmd->rfile;
	while (redir)
	{

	}
}