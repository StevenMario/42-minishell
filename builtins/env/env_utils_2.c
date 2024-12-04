/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:34:41 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/04 17:37:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

t_env	*duplicate_env(t_env *src)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	if (!new_env)
		return (NULL);
	if (src->key)
		new_env->key = ft_strdup(src->key);
	if (src->value)
		new_env->value = ft_strdup(src->value);
	new_env->next = NULL;
	return (new_env);
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
