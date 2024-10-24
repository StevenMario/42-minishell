/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:33:58 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 13:08:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
