/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 22:35:58 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// t_token	*ft_lstnew_cmd(char *content)
// {
// 	t_token	*new_token;

// 	new_token = malloc(sizeof(t_token));
// 	if (!new_token)
// 		return (NULL);
// 	new_token->prev = NULL;
// 	new_token->content = ft_strdup(content);
// 	new_token->next = NULL;
// 	return (new_token);
// }

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
		if (str[i] == ' ' || str[i] == '\n')
			i++;
		else
			break ;
	}
	while (j > i)
	{
		if (str[j] == ' ' || str[j] == '\n')
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
void	ft_lstclear_file(t_file **lst)
{
	t_file	*temp;
	t_file	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*temp;
	t_cmd	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}


