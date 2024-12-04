/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:52:00 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/04 10:10:06 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

static void	ft_sort_env(t_env **sorted_env)
{
	char	*tmp_k;
	char	*tmp_v;
	t_env	*sort;

	if (*sorted_env == NULL || (*sorted_env)->next == NULL)
		return ;
	sort = *sorted_env;
	while (sort)
	{
		if (sort && sort->next && sort->key && sort->next->key)
		{
			if (ft_strcmp(sort->key, sort->next->key) > 0)
			{
				tmp_k = sort->next->key;
				tmp_v = sort->next->value;
				sort->next->key = sort->key;
				sort->next->value = sort->value;
				sort->key = tmp_k;
				sort->value = tmp_v;
				sort = *sorted_env;
			}
			else
				sort = sort->next;
		}
		else
			break ;
	}
}

int	update_env(char *var_name, char *new_val, t_env *env)
{
	if (var_name == NULL || new_val == NULL)
		return (0);
	while (env)
	{
		if (ft_strcmp(var_name, env->key) == 0)
		{
			free(env->value);
			env->value = ft_strdup(new_val);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

static t_env	*bubble_sort_env(t_env *env)
{
	t_env	*sorted_env;

	sorted_env = duplicate_env(env);
	ft_sort_env(&sorted_env);
	return (sorted_env);
}

void	ft_print_dx(t_env *env)
{
	t_env	*sorted_env;

	sorted_env = bubble_sort_env(env);
	while (sorted_env != NULL)
	{
		printf("declare -x ");
		printf("%s=", sorted_env->key);
		printf("\"%s\"\n", sorted_env->value);
		sorted_env = sorted_env->next;
	}
}

int	take_len_bf_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
