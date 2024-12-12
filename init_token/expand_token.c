/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/12 07:29:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int sould_expand(int i,char *str,int in_s_quote)
{
	if (str[i] && str[i + 1] &&(str[i] == '$' && is_special_char(str[i + 1]))
		&& !in_s_quote)
		return (1);
	return (0);
}

char *char_append(char *str,char c)
{
	char *res;
	int len;

	len = 0;
	res = NULL;
	if (str != NULL)
		len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 2));
	if (str)
		ft_strlcpy(res,str,(len + 1));
	res[len] = c;
	res[len + 1] = '\0';
	if (str)
		free(str);
	return (res);
}

int	is_ingored_dollars(char  *str,int i,int in_d_quote,int in_s_quote)
{
	if (str[i] && str[i + 1] && (str[i] == '$'
	&& (str[i + 1] == '\'' || str[i + 1] == '"')
	&& !in_d_quote && !in_s_quote))
		return (1);
	return (0);
}

char *fill_res(char *res,int in_d_quote,int in_s_quote,char c,int i,char *str)
{
	if (!is_ingored_dollars(str,i,in_d_quote,in_s_quote))
		res = char_append(res,c);
	return (res);
}
int get_len_str(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
char **str_append(char **str,char *new_str)
{
	char **res;
	int len;
	int i;

	i = 0;
	len = 0;
	res = NULL;
	if (str != NULL)
		len = get_len_str(str);
	res = malloc(sizeof(char*) * (len + 2));
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

char **ft_split_expand(char *res)
{
	char	**expand_val;
	int		in_s_quote;
	int		in_d_quote;
	char	*temp;
	int		i;

	i = 0;
	in_s_quote = 0;
	in_d_quote = 0;
	temp = NULL;
	expand_val = NULL;
	while (res[i])
	{
		if (chech_in_quote(res[i],&in_d_quote,&in_s_quote))
		{
		}
		else if (in_d_quote || in_s_quote)
			temp = char_append(temp,res[i]);
		else if (!in_d_quote || !in_s_quote)
		{
			if (res[i] == ' ')
			{
				expand_val = str_append(expand_val,temp);
				while (res[i] && res[i] == ' ')
					i++;
				free(temp);
				temp = NULL;
			}
			temp = char_append(temp,res[i]);
		}
		if (res[i + 1] == '\0')
		{
			expand_val = str_append(expand_val,temp);
			free(temp);
			break ;
		}
		i++;
	}

	return (expand_val);
}

t_pre_expd init_t_expand(void)
{
	t_pre_expd expand;

	expand.expd_val = NULL;
	expand.res = NULL;
	expand.val_exp = NULL;
	expand.in_d_quote = 0;
	expand.in_s_quote = 0;
	return (expand);
}

// char *pre_expand(char *str, int *i, t_env *e_list, t_pre_expd expand)
// {
	
// }

char	**check_var(char *str, t_env *e_list)
{
	int		i;
	t_pre_expd expand;

	i = 0;
	expand = init_t_expand();
	if (ft_count_char_in_str(str,'$'))
	{	
		while (str[i])
		{
			if (chech_in_quote(str[i],&expand.in_d_quote,&expand.in_s_quote))
				expand.res = fill_res(expand.res,expand.in_d_quote,
					expand.in_s_quote,str[i], i,str);
			else if (sould_expand(i,str,expand.in_s_quote))
			{
				if (str[i] == '$')
					i++;
				expand.val_exp = get_val(str,&i,e_list);
				if (!expand.res && expand.val_exp)
					expand.res = ft_strdup(expand.val_exp);
				else if (expand.val_exp && expand.res)
					expand.res = ft_strjoin(expand.res,expand.val_exp);
				if (expand.val_exp)
					free(expand.val_exp);
			}
			else
				expand.res = fill_res(expand.res,expand.in_d_quote,
					expand.in_s_quote,str[i], i,str);
			if (str[i] == '\0')
				break ;
			i++;
		}
		if (expand.res)
			expand.expd_val = ft_split_expand(expand.res);
	}
	if (expand.res)
		free(expand.res);
	return (expand.expd_val);
}
