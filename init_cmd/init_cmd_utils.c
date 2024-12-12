/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:18:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/12 07:14:12 by mrambelo         ###   ########.fr       */
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

t_file	*duplicate_file(t_file *file)
{
	t_file	*new_file;

	new_file = malloc(sizeof(t_file));
	if (!new_file)
		return (NULL);
	if (file->content)
		new_file->content = ft_strdup(file->content);
	new_file->type = file->type;
	new_file->fd = file->fd;
	new_file->next = NULL;
	return (new_file);
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
