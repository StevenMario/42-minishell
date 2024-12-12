/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/12 11:25:01 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	exit_status(t_data *data)
{
	clear_data(data);
	exit(EXIT_SUCCESS);
}

void	expand_herdocc(char *input, int flag, t_env *e_lst, int *fd)
{
	char	**split_input;
	int		i;

	split_input = NULL;
	close(fd[0]);
	if (ft_count_char_in_str(input, '$') && flag == 0)
	{
		split_input = check_var(input, e_lst);
		i = -1;
		while (split_input && split_input[++i])
			ft_putendl_fd(split_input[i], fd[1]);
		if (split_input)
			ft_free_str(split_input);
		split_input = NULL;
	}
	else
		ft_putendl_fd(input, fd[1]);
	if (input)
		free(input);
}

void	fill_herdocc_fd(t_file *rfile, t_data *data, int fd[2])
{
	char	*input;
	int		flag;

	close(fd[0]);
	flag = 0;
	input = NULL;
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
			ft_free_and_close_fd(input, fd[1]);
			exit_status(data);
		}
		expand_herdocc(input, flag, data->e_lst, fd);
	}
	close(fd[1]);
}

int	create_fd_herdoc(t_data *data, t_file *rfile)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("fork");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		rl_clear_history();
		fill_herdocc_fd(rfile, data, fd);
	}
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
