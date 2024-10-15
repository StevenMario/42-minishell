/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/15 12:32:59 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void new_cmd(t_token *token)
{
	t_cmd	*new_cmd;
	t_token *temp;
	int i;

	i = 0;
	temp = token;
	while (temp)
	{
		new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return NULL;
		while (temp->type != PIPE)
		{
			if (temp->type == CMD || temp->type == INPUT
			|| temp->type == HEREDOC || temp->type == APPEND || temp->type == TRUNC)
				new_cmd->cmd = ft_strdup(temp->content);
			else
			{
				if (new_cmd->arg[i])
					i++;
				new_cmd->arg[i] = ft_strdup(temp->content);
			}
			temp = temp->next;
		}
		new_cmd = new_cmd->next;
		temp = temp->next;
	}
}
