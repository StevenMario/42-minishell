/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:12:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/23 15:01:53 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char *var_name, t_env *env)
{
	t_env	*ptr_elem;
	if (!var_name || !env)
		return ;
	if ((ptr_elem = search_env_elem(var_name, env)) == NULL)
		return ;
	
}