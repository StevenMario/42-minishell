/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:33:25 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 09:58:39 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	sould_expand(int i, char *str, int in_s_quote)
{
	if (str[i] && str[i + 1] && (str[i] == '$' && is_special_char(str[i + 1]))
		&& !in_s_quote)
		return (1);
	return (0);
}

char	*char_append(char *str, char c)
{
	char	*res;
	int		len;

	len = 0;
	res = NULL;
	if (str != NULL)
		len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 2));
	if (str)
		ft_strlcpy(res, str, (len + 1));
	res[len] = c;
	res[len + 1] = '\0';
	if (str)
		free(str);
	return (res);
}

int	is_ingored_dollars(char *str, int i, int in_d_quote, int in_s_quote)
{
	if (str[i] && str[i + 1] && (str[i] == '$' && (str[i + 1] == '\''
				|| str[i + 1] == '"') && !in_d_quote && !in_s_quote))
		return (1);
	return (0);
}

char	*fill_res(char *res, t_pre_expd	expand, int i, char *str)
{
	if (!is_ingored_dollars(str, i, expand.in_d_quote, expand.in_s_quote))
		res = char_append(res, str[i]);
	return (res);
}

int	get_len_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
