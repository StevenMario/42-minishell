/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:33:58 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/28 08:55:25 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_env_to_char(t_env *env)
{
	t_env	*tmp;
	char	**arr;
	int	i;

	i = 0;
	arr = NULL;
	tmp = env;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->key && tmp->value)
			arr[i] = double_join(tmp->key, "=", tmp->value);
	}
}
int	update_env(char *var_name, char *new_val, t_env *env)
{
	int	j;

	if (var_name == NULL || new_val == NULL)
		return ;
	j = ft_strlen(var_name);
	while(env)
	{
		if (strncmp(var_name, env->key, j) == 0)
		{
			free(env->value);
			env->value = new_val;
			return (1);
		}
		env = env->next;

	}
	return (0);
}

void	ft_rm_for_unset(t_env **env, char *var_name)
{
	t_env	*tmp;

	if (*env == NULL || var_name == NULL)
		return ;
	tmp = *env;
	if (ft_strcmp(var_name, tmp->key) == 0)
	{
		*env = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	else
	{
		ft_remove_lst(&tmp->next, var_name);
	}
}

int	ft_env_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}
