/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:12:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/15 09:33:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_rm_for_unset(t_env **env, char *var_name)
{
	t_env	*tmp;

	if (*env == NULL || var_name == NULL)
		return ;
	tmp = *env;
	if (ft_strcmp(var_name, tmp->key) == 0)
	{
		*env = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	else
	{
		ft_rm_for_unset(&tmp->next, var_name);
	}
}

int	ft_unset(t_cmd *cmd, t_env *env)
{
	int	l;

	l = 1;
	if (cmd->arg[l])
	{
		if (cmd->arg[l][0] == '-')
			printf("unset: -%c: invalid option\n", cmd->arg[l][1]);
		while (cmd->arg[l])
		{
			ft_rm_for_unset(&env, cmd->arg[l]);
			l++;
		}
		return (0);
	}
	else
		return (0);
}
