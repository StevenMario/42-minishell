/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:29:22 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/11/06 12:34:03 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../builtins.h"

int ft_env(t_cmd *cmd, t_env *env)
{
	t_env *tmp;

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
		printf("Too many arguments.\n");
		return (0);
	}
	return (1);
}
