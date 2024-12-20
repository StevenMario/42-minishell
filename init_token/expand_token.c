/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/20 16:00:07 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

char	**skip_space(char *res, int *i, char **res_expd, char **expd_val)
{
	char	**expand_value;

	expand_value = NULL;
	expand_value = str_append(expd_val, *res_expd);
	while (res[*i] && res[*i] == ' ')
	{
		if (res[*i + 1] == '\0')
			break ;
		(*i)++;
	}
	free(*res_expd);
	*res_expd = NULL;
	return (expand_value);
}

int	get_last_expd_value(char ***expd_val, char *res, char *res_expd, int *i)
{
	if (res[(*i) + 1] == '\0')
	{
		if (res_expd)
			*expd_val = str_append(*expd_val, res_expd);
		free(res_expd);
		return (1);
	}
	return (0);
}

char	**join_expd_val(char **expd_val)
{
	int	i;

	i = 0;
	while (expd_val && expd_val[i])
		i++;
	if (i > 2)
	{
		i = 1;
		while (expd_val[++i])
		{
			expd_val[1] = ft_strjoin(expd_val[1], " ");
			expd_val[1] = ft_strjoin(expd_val[1], expd_val[i]);
			if (expd_val[i])
				free(expd_val[i]);
		}
		expd_val[2] = NULL;
	}
	return (expd_val);
}

char	**ft_split_expand(char *res)
{
	t_pre_expd	expand;
	int			i;

	expand = init_t_expand();
	i = 0;
	while (res[i])
	{
		if (chech_in_quote(res[i], &expand.in_d_quote, &expand.in_s_quote))
		{
		}
		else if (expand.in_d_quote || expand.in_s_quote)
			expand.res = char_append(expand.res, res[i]);
		else if (!expand.in_d_quote || !expand.in_s_quote)
		{
			if (res[i] == ' ')
				expand.expd_val = skip_space(res, &i, &expand.res,
						expand.expd_val);
			expand.res = char_append(expand.res, res[i]);
		}
		if (get_last_expd_value(&expand.expd_val, res, expand.res, &i))
			break ;
		i++;
	}
	join_expd_val(expand.expd_val);
	return (expand.expd_val);
}

char	**check_var(char *str, t_env *e_list)
{
	int			i;
	t_pre_expd	expand;

	i = 0;
	expand = init_t_expand();
	while (str[i])
	{
		if (chech_in_quote(str[i], &expand.in_d_quote, &expand.in_s_quote))
			expand.res = fill_res(expand.res, expand, i, str);
		else if (sould_expand(i, str, expand.in_s_quote))
			expand.res = get_res(str, &i, e_list, expand.res);
		else
			expand.res = fill_res(expand.res, expand, i, str);
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (expand.res)
	{
		expand.res_trim = ft_strtrim(expand.res, " ");
		free(expand.res);
		expand.expd_val = ft_split_expand(expand.res_trim);
		free(expand.res_trim);
	}
	return (expand.expd_val);
}
