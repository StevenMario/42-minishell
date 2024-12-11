/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/11 09:52:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

char	*fill_res(int len, int j, char *str)
{
	char	*res;
	char	*temp;

	res = NULL;
	res = ft_substr(str, j, len);
	temp = ft_strtrim(res, "{}");
	free(res);
	return (temp);
}

// char	*fill_expand_value(int var_len, int j, t_env *e_list, char *str,char *value)
// {
// 	char	*res;
// 	char	*suf;
// 	char	*val;
// 	int		i;
// 	// char	*pref;

// 	i = j;
// 	j = check_dollar(str) + 1;
// 	suf = get_var_sufix(str, i);
// 	if (!value)
// 		val = my_getenv2(fill_res(var_len, j, str), e_list);
// 	// pref = get_var_prefix(str);
// 	if (!value)
// 		res = join_expand_char(val, pref, suf);
// 	else
// 		res = join_expand_char(value, pref, suf);
// 	return (res);
// }

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

int	take_len_bf_cha2(char *str, int start)
{
	int	i;

	i = 0;
	while (str[start] && !is_special_char(str[start]))
	{
		if (str[start] == '?')
		{
			i++;
			break;
		}
		start++;
		i++;
	}
	return (i);
}

char	*fill_expand_value(char *suf,char *res,char *pref)
{
	char *dest;

	if (suf && res)
		dest = ft_strjoin(suf,res);
	else if (suf && !res)
	{
		dest = ft_strdup(suf);
		free(suf);
	}
	else if (!suf && res)
	{
		dest = ft_strdup(res);
		free(res);
	}
	if (pref)
		dest = ft_strjoin(dest,pref);
	if (pref)
		free(pref);
	return(dest);
}

char	*check_var(char *str, t_env *e_list)
{
	int		j;
	int		i;
	char	*val;
	int		count_dollar;
	char	*suf;
	char	*res;
	char	*pref;
	char	*expand_value;
	
	count_dollar = ft_count_char_in_str(str, '$');
	j = 0;
	i = 0;
	val = NULL;
	res = NULL;
	pref = NULL;
	suf = NULL;
	expand_value = NULL;
	while (count_dollar)
	{
		while (str && str[j])
		{
			// if (str[j] && str[j + 1] && is_special_char(str[j + 1]))
			if (str[j] == '$' && !is_special_char(str[j + 1]))
			{
				suf = ft_substr(str, 0, j);
				j++;
				i = take_len_bf_cha2(str ,j);
				val = ft_substr(str, j, i);
				if (ft_strcmp(val,"?") == 0)
				{
					res = ft_itoa(get_status);
					free(val);
				}
				else
					res = my_getenv2(val, e_list);
				pref = get_var_prefix(str,j+i);
				if (expand_value)
					free(expand_value);
				expand_value = fill_expand_value(suf,res,pref);
				if (res)
					free(res);
				free(str);
				str = ft_strdup(expand_value);
				j--;
			}	
			j++;
		}
		count_dollar--;
	}
	free(str);
	return (expand_value);
}

void	cmd_expand(t_data *data)
{
	int		i;
	t_cmd	*cmd;

	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		if (cmd->arg)
		{
			while (cmd->arg[i])
			{
				if (check_dollar(cmd->arg[i]) > -1)
					cmd->arg[i] = check_var(cmd->arg[i], data->e_lst);
				i++;
			}
		}
		cmd = cmd->next;
	}
}
