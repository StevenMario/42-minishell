/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:52:00 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/18 09:03:34 by irabesan         ###   ########.fr       */
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

// static void ft_sort_env(t_env **sorted_env)
// {
//     t_env *current;
//    // t_env *next;
//     t_env *temp;

//     current = *sorted_env;
//     while (current && current->next)
//     {
//         if (!strcmp(current->key, current->next->key))
//         {
//             temp = current->next;
//             current->next = current->next->next;
//             current->key = temp->key;
//             current->value = temp->value;
//             temp = NULL;
//         }
//         current = current->next;
//     }
// }

int	update_env(char *var_name, char *new_val, t_env *env)
{
	if (var_name == NULL || new_val == NULL)
		return (0);
	while (env)
	{
		if (strcmp(var_name, env->key) == 0)
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
