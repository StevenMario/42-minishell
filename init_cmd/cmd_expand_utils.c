/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/07 20:07:58 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	check_dollar(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
		}
		if (str[i] == '$')
			return (i);
	}
	return (-1);
}

int	is_special_char(char c)
{
	if (c == '.' || c == '#' || c == '%'
		|| c == '^' || c == '&' || c == '*'
		|| c == '+' || c == '=' || c == '-' || c == '}'
		|| c == '\'' || c == '"' || c == ']')
		return (1);
	return (0);
}

char	*join_expand_char(char *val, char *pref, char *suf)
{
	char	*str;

	str = NULL;
	if (!val)
	{
		str = ft_strdup(" ");
		if (pref)
			str = ft_strdup(pref);
	}
	else
	{
		if (pref)
			str = ft_strjoin(pref, val);
		else
			str = ft_strdup(val);
		if (suf)
			str = ft_strjoin(str, suf);
	}
	if (val)
		free(val);
	if (suf)
		free(suf);
	return (str);
}

char	*get_var_prefix(char *str)
{
	int		i;
	int		j;
	char	*dest;

	dest = NULL;
	i = 0;
	if (str && str[i] == '$')
		return (NULL);
	j = i;
	while (str[i] && str[i] != '$')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
		}
		i++;
	}
	dest = ft_substr(str, j, i);
	return (dest);
}

char	*get_var_sufix(char *str, int var_len, int j)
{
	int		i;
	char	*dest;

	dest = NULL;
	i = 0;
	if (str[j] == '{' && str[var_len] == '}')
		i = var_len + 1;
	else
		i = var_len;
	while (str[var_len])
		var_len++;
	dest = ft_substr(str, i, var_len);
	return (dest);
}
