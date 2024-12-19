/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 08:17:29 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(t_env *env)
{
	char	env_cwd[1024];

	(void)env;
	getcwd(env_cwd, 1024);
	if ((access(env_cwd, F_OK) == 0))
		printf ("%s\n", env_cwd);
	return (0);
}
