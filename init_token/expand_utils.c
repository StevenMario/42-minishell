/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/13 10:14:35 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

char	*check_exit_status(char *check_status)
{
	char	*res;

	res = NULL;
	if (ft_strcmp(check_status, "?") == 0)
	{
		res = ft_itoa(g_status);
		free(check_status);
	}
	else
		return (free(check_status), NULL);
	return (res);
}

int	chech_in_quote(char c, int *in_d_quote, int *in_s_quote)
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

char	*init_space_val(int i, char *str)
{
	char	*val;

	val = malloc(sizeof(char) * 2);
	val[0] = str[i];
	val[1] = '\0';
	return (val);
}

char	*get_value_expand(char *str, int *i, int *len)
{
	char	*val;

	val = NULL;
	if (ft_isdigit(str[*i]))
	{
		val = init_space_val(*i, str);
		(*i)++;
	}
	else
	{
		while (str[*i] && is_special_char(str[*i]))
		{
			if (str[*i] == '?')
				break ;
			(*len)++;
			(*i)++;
		}
	}
	return (val);
}

char	*get_val(char *str, int *i, t_env *e_list)
{
	int		len;
	int		j;
	char	*val;

	val = NULL;
	len = 0;
	j = (*i);
	val = get_value_expand(str, i, &len);
	if (str[*i] == '?')
	{
		val = ft_strdup("?");
		val = check_exit_status(val);
	}
	else
	{
		if (!val)
			val = ft_substr(str, j, len);
		val = my_getenv2(val, e_list);
		(*i)--;
	}
	return (val);
}
