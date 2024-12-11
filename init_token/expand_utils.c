/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/11 18:39:08 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

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
	if (ft_isalnum(c) || c == '_' || c == '?')
		return (1);
	return (0);
}

char	*check_exit_status(char *check_status)
{
	char	*res;

	res = NULL;
	if (ft_strcmp(check_status, "?") == 0)
	{
		res = ft_itoa(get_status);
		free(check_status);
	}
	else
		return (free(check_status), NULL);
	return (res);
}



int chech_in_quote(char c,int *in_d_quote,int *in_s_quote)
{
	if (c == '\'' && !(*in_d_quote))
	{
		if (*in_s_quote == 1)
			*in_s_quote = 0;
		else
			*in_s_quote = 1;
		return (1);
	}
	if ((c == '"' && !(*in_s_quote)))
	{
		if (*in_d_quote == 1)
			*in_d_quote = 0;
		else
			*in_d_quote = 1;
		return (1);
	}
	return (0);
}

char *get_val(char *str,int *i,t_env *e_list)
{
	int len;
	int j;
	char *val;

	val = NULL;
	len = 0;
	j = (*i);
	while (str[*i] && is_special_char(str[*i]))
	{
		if (str[*i] == '?')
			break;
		len++;
		(*i)++;
	}
	if (str[*i] == '?')
	{
		val = ft_strdup("?");
		val = check_exit_status(val);
	}
	else
	{
		val = ft_substr(str,j,len);
		val = my_getenv2(val,e_list);
		(*i)--;
	}
	return (val);
}