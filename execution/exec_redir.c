/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 14:30:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_redir_builtin(t_data *mish, t_cmd *cmd, t_env *env)
{
	int	backup[2];

	if (cmd->rfile != NULL)
	{
		dup_std(backup);
		if (ft_browse_builtins(cmd, mish) == 1)
		{
			close_fds(backup);
			return (1);
		}
		mish->exit_status = ft_exec_if_builtins(cmd, mish, env);
		ft_restore_std(backup);
		close_fds(backup);
	}
	else
		mish->exit_status = ft_exec_if_builtins(cmd, mish, env);
	return (0);
}

void	check_type_for_dup2(t_file *redir)
{
	if (redir->type == INPUT || redir->type == HEREDOC)
		dup2(redir->fd, STDIN_FILENO);
	else
		dup2(redir->fd, STDOUT_FILENO);
}

void	check_error_redir(t_file *redir)
{
	struct stat	sb;

	if (redir->type == INPUT || redir->type == HEREDOC)
	{
		(void)sb;
		if (access(redir->content, F_OK) == -1)
			perror(redir->content);
		else if (access(redir->content, W_OK | R_OK | X_OK) == -1)
			perror(redir->content);
	}
	else
	{
		lstat(redir->content, &sb);
		if (access(redir->content, F_OK) == -1)
			perror(redir->content);
		else if (S_ISDIR(sb.st_mode))
			perror(redir->content);
		else if (access(redir->content, W_OK | R_OK | X_OK) == -1)
			perror(redir->content);
	}
}

void	ft_open_redir(t_file *redir)
{
	if (redir->type == TRUNC && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->type == APPEND && redir->content)
		redir->fd = open(redir->content, O_CREAT | O_APPEND | O_WRONLY, 0664);
	else if (redir->type == INPUT)
		redir->fd = open(redir->content, O_RDONLY);
	else
		return ;
}
