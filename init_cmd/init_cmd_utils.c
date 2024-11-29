/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:18:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/29 08:07:18 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	get_nb_arg(t_token *token)
{
	int	nb_token;

	nb_token = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == CMD)
			nb_token++;
		token = token->next;
	}
	return (nb_token);
}

void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*cmd = new;
	else
		temp->next = new;
}

t_cmd	*ft_initcmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->arg = NULL;
	new_cmd->rfile = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}


void	ft_lstclear_cmd(t_cmd **lst)
{

	t_cmd	*next;

	while ((*lst) != NULL)
	{
		next = (*lst)->next;
		if ((*lst)->arg)
			ft_free_str((*lst)->arg);
		if ((*lst)->rfile)
			ft_lstclear_file(&(*lst)->rfile);
		free((*lst));
		(*lst) = next;
	}
	*lst = NULL;
}
