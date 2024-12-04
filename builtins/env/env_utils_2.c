/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:34:41 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/04 12:54:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

t_env	*duplicate_env(t_env *src)
{
	t_env	*new_node;
	t_env	*head;
	t_env	*tail;
	t_env	*current;

	head = malloc(sizeof(t_env));
	if (!src || !head)
		return (NULL);
	head->key = ft_strdup(src->key);
	head->value = ft_strdup(src->value);
	head->next = NULL;
	tail = head;
	current = src->next;
	while (current)
	{
		if (!(new_node = malloc(sizeof(t_env))))
			return (NULL);
		new_node->key = ft_strdup(current->key);
		new_node->value = ft_strdup(current->value);
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
		current = current->next;
	}
	return (head);
}

t_env	*ft_double_lstnew_env(char *key, char *value)
{
	t_env		*new_env;

	new_env = init_t_env();
	if (!new_env)
		return (NULL);
	if (key)
		new_env->key = ft_strdup(key);
	if (value)
		new_env->value = ft_strdup(value);
	new_env->next = NULL;
	return (new_env);
}
