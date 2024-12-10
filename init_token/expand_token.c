/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/10 21:55:25 by mrambelo         ###   ########.fr       */
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
				while (res[i])
				{
					printf("res[i] = [%c]\n",res[i]);
					if (res[i] == ' ')
						i++;
					else
						break;;
				}
				free(temp);
				temp = NULL;
			}
			else
				temp = char_append(temp,res[i]);
		}
		if (res[i] == '\0')
		{
			printf("miditra qto\n");
			expand_val = str_append(expand_val,temp);
			break ;
		}
		i++;
	}
	i = -1;
	while (expand_val && expand_val[++i])
		printf("expand_val = %s\n",expand_val[i]);
	return (expand_val);
}

char	**check_var(char *str, t_env *e_list)
{
	int		i;
	char	*res;
	char	*val_exp;
	char	**expd_val;
	int		in_s_quote;
	int		in_d_quote;

	in_d_quote = 0;
	in_s_quote = 0;
	i = 0;
	res = NULL;
	expd_val = NULL;
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
				if (val_exp)
					free(val_exp);
			}
			else
				res = fill_res(res,in_d_quote,in_s_quote,str[i], i,str);
			if (str[i] == '\0')
				break ;
			i++;
		}
		expd_val = ft_split_expand(res);
	}
	// expd_val = malloc(sizeof(char *) * 2);
	// expd_val[0] = ft_strdup(res);
	// expd_val[1] = NULL;
	free(res);
	return (expd_val);
}
