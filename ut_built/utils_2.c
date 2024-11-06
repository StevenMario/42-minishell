/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:48:21 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 10:32:12 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void ft_sort_env(t_env **sorted_env)
{
	char	*tmp_k;
	char	*tmp_v;
	t_env	*sort;

	if (*sorted_env == NULL || (*sorted_env)->next == NULL)
		return ;
	sort = *sorted_env;
	while (sort)
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
}
static t_env	*bubble_sort_env(t_env *env)
{
	t_env	*sorted_env;

	sorted_env = env;
	ft_sort_env(&sorted_env);
	return (sorted_env);
}
