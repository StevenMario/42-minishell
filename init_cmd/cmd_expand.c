/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:26 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/29 21:09:14 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmd.h"

char *fill_res(int len,int j,char *str)
{
	char *res;

	res = (char *)malloc(sizeof(char) *len + 1);
	if (!res)
		return (NULL);
	printf("j = %d len = %d\n",j,len);
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

char	*get_var_sufix(char *str)
{
	int i;
	int j;
	char *dest;

	i = 0;
	while (str[i] && !is_special_char(str[i]))
		i++;
	j = i;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!dest)
		return (NULL);
	
	dest = ft_substr(str,j,i);
	return (dest);
}

void	check_var(char *str,t_env *e_list)
{
	int i;
	int	j;
	char *pref;
	char *res;
	char *suf;
	char *val;
	int var_len;
	i = -1;
	var_len = 0;
	suf = get_var_sufix(str);
	printf("sufix = %s\n",suf);
	while (str[++i])
	{
		if (str[i] == '$')
		{	
			i++;
			j = i;
			while (str[i] && (str[i] != ' ' && !is_special_char(str[i])
				&& str[i] != '$'))
			{
				
				var_len++;
				i++;
			}
			i--;
			pref = get_var_prefix(str);
			printf("pref = %s\n",pref);
			res = fill_res(var_len,j,str);
			printf("res = %s\n",res);
			val = my_getenv(res, e_list);
			printf("val = %s\n",val);
		}
	}
	
	// if (pref)
	// 	str = ft_strjoin(pref,val);
	
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
			if (check_dollar(cmd->arg[i]))
				check_var(cmd->arg[i],data->e_lst);
			i++;
		}
		cmd = cmd->next;	
	}
}