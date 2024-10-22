/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:07:43 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 11:08:54 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			new->prev = temp;
			new->next = NULL;
			break ;
		}
		temp = temp->next;
	}
}

t_token	*ft_double_lstnew_token(char *content)
{
	t_token		*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->prev = NULL;
	new_token->content = ft_strdup(content);
	new_token->next = NULL;
	return (new_token);
}

void ft_print_token(t_token *token)
{
	while (token)
	{
		printf("data->token->content == %s  {}  data->token->type == %d   \n",token->content,token->type);
		token = token->next;
	}
}