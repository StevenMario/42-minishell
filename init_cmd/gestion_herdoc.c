/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/27 10:34:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void printf_rfile(t_file *rfile)
{

		printf("---------------------------------------\n");
		while (rfile)
		{
			if (rfile->type == HEREDOC || rfile->type == INPUT)
				printf("=============INFILE================\n");
			else
				printf("=============OUTFILE================\n");
			printf(" type = %d\n",rfile->type);
			if (rfile->content)
				printf("content = %s\n",rfile->content);
			rfile = rfile->next;
		}
		
}

void exit_status(t_data *data)
{
	clear_data(data);
	exit(0);
}

void fill_herdocc_fd(t_file *rfile,t_data *data,int *fd)
{
	char *input;

	close(fd[0]);
	// close(fd[1]);
	while (1)
	{
		input = readline(">>");
		if (input == NULL )
			exit_status(data);
		if (ft_strcmp(input,rfile->content) == 0)
		{
			free(input);
			exit_status(data);
		}
		expand_variable(input);
		ft_putendl_fd(input,fd[1]);
		free(input);
	}
}

void create_fd_herdoc(t_data *data,t_file *rfile)
{
	int pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
		fill_herdocc_fd(rfile,data,fd);
	wait(NULL);
	close(fd[1]);
	rfile->fd = fd[0];
}

void herdoc_handler(t_data *data)
{
	while (data->cmd)
	{
		while (data->cmd->rfile)
		{
			if (data->cmd->rfile->type == HEREDOC)
				create_fd_herdoc(data,data->cmd->rfile);
			data->cmd->rfile = data->cmd->rfile->next;
		}
		data->cmd = data->cmd->next;
	}
}