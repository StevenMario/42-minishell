/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:13:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 16:45:55 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_cmd	*ft_initcmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->arg = NULL;
	new_cmd->rfile = NULL;
	new_cmd->next = NULL;
	new_cmd->pid = 0;
	new_cmd->status = 0;
	return (new_cmd);
}

void	ft_free_and_close_fd(char *input, int fd)
{
	free(input);
	close(fd);
}

void	exit_status(t_data *data)
{
	clear_data(data);
	exit(EXIT_SUCCESS);
}

void	sig_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		g_status = SIGINT;
		close(STDIN_FILENO);
	}
}

void	clear_fd(t_data *data)
{
	t_cmd	*cmd;
	t_file	*rfile;

	cmd = data->cmd;
	while (cmd)
	{
		rfile = cmd->rfile;
		close_herdocc_fd(rfile);
		cmd = cmd->next;
	}
}
