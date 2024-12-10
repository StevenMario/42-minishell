/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:29:22 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/10 15:10:59 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	ft_env(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;

	if (cmd->arg[1] == NULL)
	{
		tmp = env;
		while (tmp)
		{
			printf("%s", tmp->key);
			printf("=");
			printf("%s\n", tmp->value);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_error_writer("env", " :too many arguments\n");
		return (0);
	}
	return (1);
}
