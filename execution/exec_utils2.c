/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:16:15 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 14:37:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handling_signal_parents(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	handling_signal_child(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

int	is_signal(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->status == 130)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	clear_data_without_env(t_data *data)
{
	if (data)
	{
		if (data->cmd)
			ft_lstclear_cmd(&data->cmd);
		if (data->token)
			ft_lstclear_token(&data->token);
	}
}

void	ft_perror(char *m_err)
{
	perror(m_err);
	exit(EXIT_FAILURE);
}
