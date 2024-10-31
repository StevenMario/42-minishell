/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/31 13:43:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmd.h"

char *fill_res(int len,int j,char *str)
{
	char *res;

	res = (char *)malloc(sizeof(char) *len + 1);
	if (!res)
		return (NULL);
	// printf("j = %d len = %d\n",j,len);
	res = ft_substr(str,j,len);
	res = ft_strtrim(res,"{}");
	return (res);
}

char	*get_var_prefix(char *str)
{
	int i;
	char *dest;

	i = 0;
	if (str[0] == '$')
		return (NULL);
	while (str[i] && str[i] != '$')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest = ft_substr(str,0,i);
	return (dest);
}

char	*get_var_sufix(char *str,int var_len,int j)
{
	int i;
	char *dest;

	i = 0;
	// printf("str[j] = %c   str[var_LEN + 1] = %c\n",str[j],str[var_len + 1]);
	if (str[j] == '{' && str[var_len] == '}')
		i = var_len + 1;
	else
		i = var_len;
	while (str[var_len])
		var_len++;
	dest = (char *)malloc(sizeof(char) * (var_len - i + 1));
	if (!dest)
		return (NULL);
	// printf("str[i] = %c\n",str[i]);
	dest = ft_substr(str,i,var_len);
	return (dest);
}

char *check_var(char *str,t_env *e_list)
{
	int j;
	int i;
	// char *pref;
	char *res;
	char *suf;
	char *val;
	int var_len;

	var_len = 0;
	j = check_dollar(str) + 1;
	while (str[j] && (str[j] != ' ' && !is_special_char(str[j])
		&& str[j] != '$'))
	{
		var_len++;
		j++;
	}
	i = j;
	j = check_dollar(str) + 1;
	// pref = get_var_prefix(str);
	res = fill_res(var_len,j,str);
	suf = get_var_sufix(str,i,j);
	val = my_getenv(res, e_list);
	str = join_expand_char(val, get_var_prefix(str), suf); 
	printf("str = %s\n",str);
	return (str);
}

void cmd_expand(t_data *data)
{
	int i;
	t_cmd *cmd;

	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->arg[i])
		{
			if (check_dollar(cmd->arg[i]) > -1)
				cmd->arg[i] = check_var(cmd->arg[i],data->e_lst);
			i++;
		}
		cmd = cmd->next;	
	}
}