/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:33:58 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/23 14:14:27 by irabesan         ###   ########.fr       */
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