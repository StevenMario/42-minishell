/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/12 11:32:14 by irabesan         ###   ########.fr       */
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
	if (str[i] && str[i + 1] && (str[i] == '$'
			&& (str[i + 1] == '\'' || str[i + 1] == '"')
			&& !in_d_quote && !in_s_quote))
		return (1);
	return (0);
}

char	*fill_res(char *res, int in_d_quote, int in_s_quote, char c, int i,
		char *str)
{
	if (!is_ingored_dollars(str, i, in_d_quote, in_s_quote))
		res = char_append(res, c);
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
		*expd_val = str_append(*expd_val, res_expd);
		free(res_expd);
		return (1);
	}
	return (0);
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
	return (expand.expd_val);
}

char	*get_res(char *str, int *i, t_env *e_lst, char *expd_res)
{
	char	*val_exp;

	val_exp = NULL;
	if (str[*i] == '$')
		(*i)++;
	val_exp = get_val(str, i, e_lst);
	if (!expd_res && val_exp)
		expd_res = ft_strdup(val_exp);
	else if (val_exp && expd_res)
		expd_res = ft_strjoin(expd_res, val_exp);
	if (val_exp)
		free(val_exp);
	return (expd_res);
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
			expand.res = fill_res(expand.res, expand.in_d_quote,
					expand.in_s_quote, str[i], i, str);
		else if (sould_expand(i, str, expand.in_s_quote))
			expand.res = get_res(str, &i, e_list, expand.res);
		else
			expand.res = fill_res(expand.res, expand.in_d_quote,
					expand.in_s_quote, str[i], i, str);
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (expand.res)
	{
		expand.expd_val = ft_split_expand(expand.res);
		free(expand.res);
	}
	return (expand.expd_val);
}
