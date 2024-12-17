/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 12:41:24 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(t_env *env)
{
	char	env_cwd[1024];
	char	*home;

	(void)env;
	home = NULL;
	getcwd(env_cwd, 1024);
	if ((access(env_cwd, F_OK) == 0))
		printf ("%s\n", env_cwd);
	return (0);
}
