/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/06 12:28:54 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(t_env *env)
{
	char *env_cwd;

	env_cwd = NULL;
	env_cwd = my_getenv("PWD", env);
	if (env_cwd == NULL)
		return (1);
	printf ("%s\n", env_cwd);
	return (0);
}
