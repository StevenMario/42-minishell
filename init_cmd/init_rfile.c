/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:19:49 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/20 11:07:55 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_file	*ft_init_file(void)
{
	t_file	*rfile;

	rfile = malloc(sizeof(t_file));
	if (!rfile)
		return (NULL);
	rfile->next = NULL;
	rfile->content = NULL;
	rfile->fd = 0;
	return (rfile);
}

void	ft_add_back_rfile(t_file **rfile, t_file *new_file)
{
	t_file	*temp;

	temp = *rfile;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*rfile = new_file;
	else
		temp->next = new_file;
	temp = NULL;
}

int	init_file(t_token *token, t_cmd *cmd)
{
	t_file	*temp;

	temp = NULL;
	if (token->next && (token->type == INPUT || token->type == HEREDOC
			|| token->type == TRUNC || token->type == APPEND))
	{
		temp = ft_init_file();
		temp->content = ft_strdup(token->next->content);
		if (token->next->in_quote == 1)
			temp->in_quote = 1;
		else
			temp->in_quote = 0;
		if (token->type == INPUT)
			temp->type = INPUT;
		else if (token->type == HEREDOC)
			temp->type = HEREDOC;
		else if (token->type == TRUNC)
			temp->type = TRUNC;
		else if (token->type == APPEND)
			temp->type = APPEND;
		ft_add_back_rfile(&cmd->rfile, temp);
		return (1);
	}
	return (0);
}
