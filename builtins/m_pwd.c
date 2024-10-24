/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:54:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 11:48:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char *env_cwd;

	env_cwd = NULL;
	env_cwd = getcwd(env_cwd, sizeof(env_cwd));
	if (env_cwd == NULL)
		return (1);
	printf ("%s\n", env_cwd);
	return (0);
}
