/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/03 10:52:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void exit_status(t_data *data)
{
	clear_data(data);
	exit(0);
}

char *expand_variable(char *input,t_data *data)
{
	input = check_var(input,data->e_lst);
	return (input);
}

void fill_herdocc_fd(t_file *rfile,t_data *data,int *fd)
{
	char *input;
	int flag;

	close(fd[0]);
	flag = 0;
	if (ft_count_char_in_str(rfile->content,'"') || ft_count_char_in_str(rfile->content,'\''))
	{
		rfile->content = remove_quotes(rfile->content);
		flag = 1;
	}	
	while (1)
	{
		input = readline(">>");
		if (input == NULL)
			exit_status(data);
		if (ft_strcmp(input,rfile->content) == 0)
		{
			free(input);
			exit_status(data);
		}
		if (ft_count_char_in_str(input,'$') && flag == 0)
			input = expand_variable(input, data);
		ft_putendl_fd(input,fd[1]);
		free(input);
	}
}

int create_fd_herdoc(t_data *data,t_file *rfile)
{
	int pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
		fill_herdocc_fd(rfile,data,fd);
	wait(NULL);
	close(fd[1]);
	return (fd[0]);
}

void	herdoc_handler(t_data *data)
{
	t_cmd *temp;
	t_file *tfile_tmp;
	temp = data->cmd;
	while (temp)
	{
		tfile_tmp = temp->rfile;
		while (tfile_tmp)
		{
			if (tfile_tmp->type == HEREDOC)
				tfile_tmp->fd = create_fd_herdoc(data,tfile_tmp);
			tfile_tmp = tfile_tmp->next;
		}
		temp = temp->next;
	}
}