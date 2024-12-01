/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/01 11:04:55 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

char	*fill_res(int len, int j, char *str)
{
	char	*res;

	res = NULL;
	res = ft_substr(str, j, len);
	res = ft_strtrim(res, "{}");
	return (res);
}

char	*fill_expand_value(int var_len, int j, t_env *e_list, char *str)
{
	char	*res;
	char	*suf;
	char	*val;
	int		i;
	char	*pref;

	i = j;
	j = check_dollar(str) + 1;
	suf = get_var_sufix(str, i, j);
	val = my_getenv(fill_res(var_len, j, str), e_list);
	pref = get_var_prefix(str);
	res = join_expand_char(val, pref, suf);
	// free(suf);
	return (res);
}

char	*check_var(char *str, t_env *e_list)
{
	int		j;
	char	*res;
	int		var_len;
	int		count_dollar;

	count_dollar = ft_count_char_in_str(str, '$');
	while (count_dollar > 0)
	{
		var_len = 0;
		j = check_dollar(str) + 1;
		while (str[j] && (str[j] != ' ' && !is_special_char(str[j])
				&& str[j] != '$'))
		{
			var_len++;
			j++;
		}
		res = fill_expand_value(var_len, j, e_list, str);
		free(str);
		str = ft_strdup(res);
		count_dollar--;
	}
	free(str);
	return (res);
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
