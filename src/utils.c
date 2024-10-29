/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/29 10:45:10 by mrambelo         ###   ########.fr       */
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

char *remove_quotes(char *str)
{
	size_t len ;
	char *result;
	char *dst;
	const char *src;
	
	len = ft_strlen(str);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return NULL;
	src = str;
	dst = result;
	while (*src)
	{
		if (*src != '"' && *src != '\'')
			*dst++ = *src;
		src++;
	}
	*dst = '\0';
	free(str);
	return result;
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
	while (str && str[i])
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

char is_quote(char str)
{
	if (str == '\'' || str == '"')
		return (str);
	return (0);
}

int check_quote(char *str)
{
	int i;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
	}
	return (0);
}



