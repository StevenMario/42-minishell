/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/02 09:53:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env)
{
	if (ft_is_builtin(cmd) == 1)
	{
		exec_redir_builtin(mish, cmd, env);
		return (0);
	}
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
		{
			perror("fork");
			clear_data(mish);
			exit(EXIT_FAILURE);
		}
		else if (cmd->pid == 0)
		{
			if (cmd->rfile != NULL)
				ft_browse_redir(cmd);
			exec_extern_cmd(env, cmd);
			clear_data(mish);
			rl_clear_history();
			exit(1);
		}
		waitpid(cmd->pid, &mish->exit_status, 0);
		mish->exit_status = get_exit_status(mish->exit_status);
		clear_data(mish);
	}
	return (0);
}

void	set_pipe_cmd(t_data *mish,t_cmd *cmd) // link_cmd
{
	int fds[2];

	if(pipe(fds) == -1)
	{
		perror("pipe");
        exit(EXIT_FAILURE);
	}
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		if (cmd->next != NULL)
			dup2(fds[1], STDOUT_FILENO);
		close_fds(fds);
		exec_simple_cmd(mish, cmd, mish->e_lst);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close_fds(fds);
	}
}

void clear_data_without_env(t_data *data)
{
	if (data)
	{
		if (data->cmd)
			ft_lstclear_cmd(&data->cmd);
		if (data->token)
			ft_lstclear_token(&data->token);
		// if (data->e_lst)
		// 	ft_lstclear_env(&data->e_lst);
		// free(data);
	}
}

void	piping_cmd(t_data *mish, int backup[2]) //pipeline
{
	t_cmd *cmd;
	int count;

    count = ft_count_cmd(mish);
	cmd = mish->cmd;
	if (count == 1)
	{
		exec_simple_cmd(mish, cmd, mish->e_lst);
		return ;
	}
	dup_std(backup);
	while (cmd)
	{
		set_pipe_cmd(mish, cmd);
		cmd = cmd->next;
	}
	cmd = mish->cmd;
	while (cmd)
	{
		if (cmd->next == NULL)
			waitpid(cmd->pid, &mish->exit_status, 0);
		else
			waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	mish->exit_status = get_exit_status(mish->exit_status);
	ft_restore_std(backup);
	close_fds(backup);
	clear_data_without_env(mish);
}
