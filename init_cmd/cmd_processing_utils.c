/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_processing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:14:37 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/09 21:34:43 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

char	*my_getenv(char *var_name, t_env *env)
{
	t_env	*tmp;
	char	*val;

	if (!var_name)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(var_name, tmp->key) == 0)
		{
			val = ft_strdup(tmp->value);
			return (val);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*my_getenv2(char *var_name, t_env *env)
{
	t_env	*tmp;
	char	*val;

	if (!var_name)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(var_name, tmp->key) == 0)
		{
			val = ft_strdup(tmp->value);
			free(var_name);
			return (val);
		}
		tmp = tmp->next;
	}
	free(var_name);
	var_name = NULL;
	return (NULL);
}
