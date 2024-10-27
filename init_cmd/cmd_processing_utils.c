/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_processing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:14:37 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/27 22:05:45 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

char	*my_getenv(char *var_name, t_env *env)
{
	// int	j;
	t_env	*tmp;

	if (!var_name)
		return (NULL);
	// j = ft_strlen(var_name);
	tmp = env;
	while (tmp)
	{
		
        if (ft_strcmp(var_name, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}