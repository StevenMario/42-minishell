/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:50:03 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 17:03:25 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	ft_clear_sigint(t_data *data, int fd)
{
	clear_fd(data);
	close(fd);
	clear_data(data);
	exit(130);
}

void	ft_pre_herdoc(t_data *data, t_file *rfile, int fd[2])
{
	rl_clear_history();
	signal(SIGINT, sig_heredoc);
	signal(SIGQUIT, SIG_IGN);
	fill_herdocc_fd(rfile, data, fd);
	if (g_status == SIGINT)
		ft_clear_sigint(data, fd[1]);
}
