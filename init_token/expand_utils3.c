/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:38:57 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 19:11:41 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

char	**str_append(char **str, char *new_str)
{
	char	**res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	res = NULL;
	if (str != NULL)
		len = get_len_str(str);
	res = malloc(sizeof(char *) * (len + 2));
	if (str)
	{
		while (i < len)
		{
			res[i] = ft_strdup(str[i]);
			i++;
		}
	}
	res[len] = ft_strdup(new_str);
	res[len + 1] = NULL;
	if (str)
		ft_free_str(str);
	return (res);
}

t_pre_expd	init_t_expand(void)
{
	t_pre_expd	expand;

	expand.expd_val = NULL;
	expand.res = NULL;
	expand.in_d_quote = 0;
	expand.in_s_quote = 0;
	return (expand);
}

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
