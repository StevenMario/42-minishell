/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/08 08:40:23 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*remove_quotes(char *str)
{
	size_t		len;
	char		*result;
	char		*dst;
	const char	*src;
	char c;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	src = str;
	dst = result;
	while (src[j])
	{
		if (src[j] == '\'' || src[j] == '"')
		{
			c = src[j];
			break;
		}	
			
		j++;
	}
	j = 0;
	while (src[j])
	{
		if (src[j] != c)
		{
			dst[i] = src[j];
			printf("dst[i] = %c\n",dst[i]);
			i++;
		}		
		j++;
	}
	dst[i] = '\0';
	free(str);
	return (result);
}

char	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (c);
	return (0);
}

int	check_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
	}
	return (0);
}
