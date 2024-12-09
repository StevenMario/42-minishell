/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/09 22:23:23 by mrambelo         ###   ########.fr       */
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
		|| c == '\'' || c == '"' || c == ']'|| c == '$'
		|| c == ' ')
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

char	*get_var_prefix(char *str,int start)
{
	char *dest;
	int i;
	int j;

	i = 0;
	j = 0;
	dest = NULL;
	i = start;
	while (str[start])
	{
		start++;
		j++;
	}	
	dest = ft_substr(str,i,j);
	return (dest);
}

char	*get_var_sufix(char *str, int var_len)
{
	int		i;
	char	*dest;

	dest = NULL;
	i = 0;
	i = var_len;
	while (str[var_len])
		var_len++;
	dest = ft_substr(str, i, var_len);
	return (dest);
}
