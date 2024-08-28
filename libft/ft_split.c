/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:17:15 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/24 09:17:18 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*fill_word(char const *s, size_t len)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}

static char	**stock_world(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i - j > 0)
		{
			result[k] = fill_word(s + j, i - j);
			k++;
		}
	}
	result[k] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**result;

	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	result = stock_world(s, c, str);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
