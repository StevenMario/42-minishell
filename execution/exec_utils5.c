/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:38:39 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 15:49:01 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_path_n(t_env *env, char *cmd)
{
	char	*path_n[2];
	char	*path;

	path = NULL;
	path_n[0] = my_getenv("PWD", env);
	path_n[1] = NULL;
	path = ft_test_access(path_n, cmd);
	if (path_n[0])
		free(path_n[0]);
	return (path);
}

int	check_errno(char *path)
{
	perror(path);
	if (errno == 2)
		return (127);
	else if (errno == 20)
		return (126);
	return (0);
}

char	*double_join_env(char *s1, char *s2)
{
	char	*r1;

	if (!s1)
		return (NULL);
	r1 = ft_join_env(s1, "=");
	if (!r1)
		return (NULL);
	r1 = ft_strjoin(r1, s2);
	if (!r1)
		return (NULL);
	return (r1);
}

char	*double_join_env1(char *s1, char *s2)
{
	char	*r1;

	if (!s1)
		return (NULL);
	r1 = ft_join_env(s1, "/");
	if (!r1)
		return (NULL);
	r1 = ft_strjoin(r1, s2);
	if (!r1)
		return (NULL);
	return (r1);
}
