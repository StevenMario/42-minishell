/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:07:43 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/20 09:34:14 by mrambelo         ###   ########.fr       */
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
			return ;
		}
		temp = temp->next;
	}
}

t_token	*ft_double_lstnew_token(char *content,int status,int is_expand)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->prev = NULL;
	if (content)
		new_token->content = ft_strdup(content);
	// if (ft_count_char_in_str(content, '"') || ft_count_char_in_str(content,
	// 		'\''))
	// 	new_token->in_quote = 1;
	// else
	new_token->in_quote = status;
	new_token->is_expand = is_expand;
	new_token->next = NULL;
	return (new_token);
}

void	ft_lstclear_token(t_token **lst)
{
	t_token	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
