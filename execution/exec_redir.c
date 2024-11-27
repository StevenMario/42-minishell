/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/27 16:34:07 by iarantsoa        ###   ########.fr       */
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

void check_error_redir(t_file *redir)
{
	if (access(redir->content, F_OK) == -1)
		printf("minishell: %s: No such file or directory\n", redir->content);
	else if (access(redir->content, W_OK | R_OK | X_OK == -1))
		printf("minishell: %s: Permission denied\n", redir->content);
	else
		return ;
}
void	ft_open_redir(t_file *redir)
{
	if (redir->type == TRUNC && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->type == APPEND && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_APPEND | O_WRONLY, 0664);
	else if (redir->type == INPUT)
		redir->fd = open(redir->content, O_RDONLY)
	else
		return ;
}

int	ft_browse_redir(t_cmd *cmd)
{
	t_file *redir;

	redir = cmd->rfile;
	while (redir)
	{
		ft_open_redir(redir);
		if (redir->fd == -1)
			check_error_redir(redir);
		check_type_for_dup2(redir);
		close(redir->fd);
		redir = redir->next;
		
	}
}