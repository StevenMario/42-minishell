/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/23 18:58:20 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char *env_cwd;

	env_cwd = NULL;
	env_cwd = getcwd(env_cwd, sizeof(env_cwd));
	if (env_cwd == NULL)
		return (NULL);
	printf ("%s\n", env_cwd);
	return (0);
}
