/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:12:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 11:40:21 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_cmd *cmd, t_env *env)
{
	int	l;

	l = 1;
	if (cmd->arg[l])
	{
		while (cmd->arg[l])
		{
			ft_rm_for_unset(&env, cmd->arg[l]);
			l++;
		}
		return (0);
	}
	else
		return (1);

}