/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/02 08:46:44 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(t_env *env)
{
	(void)env;
	char	env_cwd[1024];

	//env_cwd = NULL;
	getcwd(env_cwd, 1024);
	// env_cwd = my_getenv("PWD", env);
	// if (env_cwd == NULL)
	// 	return (1);
	printf ("%s\n", env_cwd);
	return (0);
}
