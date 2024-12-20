/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/20 16:12:18 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	check_redir_type(int check)
{
	if (check == PIPE || check == APPEND || check == INPUT || check == TRUNC
		|| check == HEREDOC)
		return (1);
	return (0);
}

int	check_redir_type2(int check)
{
	if (check == APPEND || check == INPUT || check == TRUNC || check == HEREDOC)
		return (1);
	return (0);
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

char	*remove_quote_process(char *str)
{
	int		i;
	char	*res;
	int		in_s_quote;
	int		in_d_quote;

	res = NULL;
	i = -1;
	in_d_quote = 0;
	in_s_quote = 0;
	while (str[++i])
	{
		if (chech_in_quote(str[i], &in_d_quote, &in_s_quote))
		{
		}
		else
			res = char_append(res, str[i]);
	}
	return (res);
}

void	add_token(t_data *data, t_tk tk)
{
	int	i;

	i = -1;
	while (tk.expand_val && tk.expand_val[++i])
	{
		if (data->token == NULL)
			data->token = ft_double_lstnew_token(tk.expand_val[i], tk.status,
					tk.is_expand);
		else
			ft_lstadd_back_token(&data->token,
				ft_double_lstnew_token(tk.expand_val[i], tk.status,
					tk.is_expand));
	}
}
