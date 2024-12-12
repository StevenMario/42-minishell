/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/12 07:43:20 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_redir_builtin(t_data *mish, t_cmd *cmd, t_env *env)
{
	int	backup[2];

	if (cmd->rfile != NULL)
	{
		dup_std(backup);
		ft_browse_redir(cmd);
		mish->exit_status = ft_exec_if_builtins(cmd, mish, env);
		ft_restore_std(backup);
		close_fds(backup);
	}
	else
		mish->exit_status = ft_exec_if_builtins(cmd, mish, env);
}

void	check_type_for_dup2(t_file *redir)
{
	if (redir->type == TRUNC || redir->type == APPEND)
		dup2(redir->fd, STDOUT_FILENO);
	else
		dup2(redir->fd, STDIN_FILENO);
}

void	check_error_redir(t_file *redir)
{
	struct stat	sb;

	if (redir->type == INPUT || redir->type == HEREDOC)
	{
		(void)sb;
		if (access(redir->content, F_OK) == -1)
			printf("mish: %s: No such file or directory\n", redir->content);
		if (access(redir->content, W_OK | R_OK | X_OK) == -1)
			printf("mish: %s: Permission denied\n", redir->content);
	}
	else
	{
		lstat(redir->content, &sb);
		if (S_ISDIR(sb.st_mode))
			printf("mish: %s: is a directory\n", redir->content);
		if (access(redir->content, W_OK | R_OK | X_OK) == -1)
			printf("mish: %s: Permission denied\n", redir->content);
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

void	ft_browse_redir(t_cmd *cmd)
{
	t_file	*redir;

	redir = cmd->rfile;
	while (redir)
	{
		ft_open_redir(redir);
		if (redir->fd == -1)
		{
			check_error_redir(redir);
			exit(EXIT_FAILURE);
		}
		check_type_for_dup2(redir);
		close(redir->fd);
		redir = redir->next;
	}
}
