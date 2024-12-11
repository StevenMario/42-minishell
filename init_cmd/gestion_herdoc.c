/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/11 10:10:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	exit_status(t_data *data)
{
	clear_data(data);
	exit(EXIT_SUCCESS);
}

void	fill_herdocc_fd(t_file *rfile, t_data *data, int fd[2])
{
	char	*input;
	char	**split_input;
	int		i;
	int		flag;

	close(fd[0]);
	flag = 0;
	i = -1;
	input = NULL;
	split_input = NULL;
	if (ft_count_char_in_str(rfile->content, '"')
		|| ft_count_char_in_str(rfile->content, '\''))
	{
		rfile->content = remove_quote_process(rfile->content);
		flag = 1;
	}
	while (1)
	{
		input = readline(">>");
		if (input == NULL)
			exit_status(data);
		if (ft_strcmp(input, rfile->content) == 0)
		{
			free(input);
			close(fd[1]);
			exit_status(data);
		}
		if (ft_count_char_in_str(input, '$') && flag == 0)
		{
			split_input = check_var(input, data->e_lst);
			while (split_input[++i])
				ft_putendl_fd(split_input[i], fd[1]);
			if (split_input)
				ft_free_str(split_input);
		}	
		else
			ft_putendl_fd(input, fd[1]);
		if (input)
			free(input);
		
	}
	
}

int	create_fd_herdoc(t_data *data, t_file *rfile)
{
	int	pid;
	int	fd[2];

	if(pipe(fd) == -1)
	{
		perror("fork");
		return (1);
	}
	pid = fork();
	if (pid == 0)
		fill_herdocc_fd(rfile, data, fd);
	wait(NULL);
	close(fd[1]);
	return (fd[0]);
}

void	herdoc_handler(t_data *data)
{
	t_cmd	*temp;
	t_file	*tfile_tmp;

	temp = data->cmd;
	while (temp)
	{
		tfile_tmp = temp->rfile;
		while (tfile_tmp)
		{
			if (tfile_tmp->type == HEREDOC)
				tfile_tmp->fd = create_fd_herdoc(data, tfile_tmp);
			tfile_tmp = tfile_tmp->next;
		}
		temp = temp->next;
	}
}
