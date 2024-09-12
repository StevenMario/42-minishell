/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/12 10:42:11 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew_cmd(char *content)
{
	t_token	*new_stack;

	new_stack = malloc(sizeof(t_token));
	if (!new_stack)
		return (NULL);
	new_stack->prev = NULL;
	new_stack->content = ft_strdup(content);
	new_stack->next = NULL;
	return (new_stack);
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
	//printf("str = %s\n",str);
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
	while (i < j)
	{
		dest[k++] = str[i++];
		//printf("str[i] = %c\n",str[i]);
	}
	dest[k] = '\0';
	//printf("dest = %s\n",dest);
	free(str);
	return (dest);
}
