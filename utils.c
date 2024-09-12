/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/12 20:41:56 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
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

t_token	*ft_double_lstnew(char *content)
{
	t_token		*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->prev = NULL;
	new_token->content = ft_strdup(content);
	printf("%s\n",new_token->content);
	new_token->next = NULL;
	return (new_token);
}

t_token	*ft_lstnew_cmd(char *content)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->prev = NULL;
	new_token->content = ft_strdup(content);
	new_token->next = NULL;
	return (new_token);
}

char *ft_remove_front_and_back_space(char *str)
{
	char *dest;
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	j = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	while (j > i)
	{
		if (str[j] == ' ')
			j--;
		else 
			break;
	}
	dest = malloc(sizeof(char) * (j - i + 1));
	if (!dest)
		return (NULL);
	while (i < j)
		dest[k++] = str[i++];
	dest[k] = '\0';
	free(str);
	return (dest);
}
