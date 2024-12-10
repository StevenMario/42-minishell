/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/10 15:18:44 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

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

char	**check_var(char *str, t_env *e_list)
{
	int		i;
	int		j;
	char	**tmp_exp;
	char	*res;
	char	*val_exp;
	char	**expd_val;
	int		in_s_quote;
	int		in_d_quote;

	in_d_quote = 0;
	in_s_quote = 0;
	i = 0;
	j = -1;
	res = NULL;
	expd_val = NULL;
	tmp_exp = NULL;
	if (ft_count_char_in_str(str,'$'))
	{	
		while (str[i])
		{
			if (chech_in_quote(str[i],&in_d_quote,&in_s_quote))
				res = fill_res(res,in_d_quote,in_s_quote,str[i], i,str);
			else if (sould_expand(i,str,in_s_quote))
			{
				if (str[i] == '$')
					i++;
				val_exp = get_val(str,&i,e_list);
				if (!res)
					res = ft_strdup(val_exp);
				else if (val_exp && res)
					res = ft_strjoin(res,val_exp);
			}
			else
				res = fill_res(res,in_d_quote,in_s_quote,str[i], i,str);
			if (str[i] == '\0')
				break ;
			i++;
		}
		printf("res = %s\n",res);
	}
	expd_val = malloc(sizeof(char *) * 2);
	expd_val[0] = ft_strdup(res);
	expd_val[1] = NULL;
	return (expd_val);
}
