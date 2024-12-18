/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/18 20:41:18 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	signal_heredoc_handler(void)
{
	struct sigaction	action;

	memset(&action, 0, sizeof(action));
	action.sa_handler = sig_heredoc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT, SIG_IGN);
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
		if (g_status == SIGINT)
			break ;
		if (input == NULL || ft_strcmp(input, rfile->content) == 0)
		{
			clear_fd(data);
			ft_free_and_close_fd(input, fd[1]);
			close_herdocc_fd(data->cmd->rfile);
			exit_status(data);
		}
		expand_herdocc(input, flag, data->e_lst, fd);
	}
}

int	create_fd_herdoc(t_data *data, t_file *rfile)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	handling_signal_parents();
	if (pid == 0)
	{
		
		close(fd[0]);
		ft_pre_herdoc(data, rfile, fd);
		exit(0);
	}
	waitpid(pid, &data->exit_status, 0);
	data->exit_status = get_exit_status(data->exit_status);
	if (data->exit_status == 130)
	{
		close_fds(fd);
		return (-1);
	}
	close(fd[1]);
	return (fd[0]);
}

int	herdoc_handler(t_data *data)
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
			{
				tfile_tmp->fd = create_fd_herdoc(data, tfile_tmp);
				if (tfile_tmp->fd == -1)
					return (1);
				if (tfile_tmp->next && tfile_tmp->next->type == HEREDOC)
					close(tfile_tmp->fd);
			}
			tfile_tmp = tfile_tmp->next;
		}
		temp = temp->next;
	}
	return (0);
}
