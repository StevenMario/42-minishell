/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:48:21 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/22 14:51:54 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_dx(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		printf("declare -x ");
		printf("%s=", env->key);
		printf(""%s"\n", env->value);
		env = env->next;
	}

}
static void	swap(t_env **a)
{
	t_env	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	(*a)->prev = tmp;
	(*a)->next->prev = (*a);
	(*a) = tmp;


}
void ft_sort_env(t_env **sorted_env)
{
	t_env	*tmp;
	t_env	*sort;

	if (*sort_env == NULL || (*a)->next == NULL)
		return ;
	sort = *sorted_env;
	while (sort)
	{
		if (ft_strcmp(sort->key, sort->next->key) > 0)
		{
			swap(&sort);
			sort = *sorted_env;
		}
		else
			sort = sort->next;

	}
}
t_env	*bubble_sort_env(t_env *env)
{
	t_env	*sorted_env;

	sorted_env = env;
	ft_sort_env(&sorted_env);
}
