/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_builtins_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:01:36 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/05 07:56:42 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_env_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**split_for_path(t_env *env)
{
	char	**arr;
	char	*content;

	arr = NULL;
	content = my_getenv("PATH", env);
	if (!env || content == NULL)
		return (NULL);
	arr = ft_split(content, ':');
	if (!arr)
		return (NULL);
	return (arr);
}

char	*ft_join_env(char *s1, char *s2)
{
	char	*str;
	size_t	s1_i;
	size_t	s2_i;

	s1_i = ft_strlen(s1);
	s2_i = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_i + 1);
	ft_strlcat(str, s2, s2_i + s1_i + 1);
	return (str);
}

void	ft_free_env2d_pathspl(char **env_2d, char **path_spl, char *path)
{
	if (env_2d)
		ft_free_str(env_2d);
	if (path_spl)
		ft_free_str(path_spl);
	if (path)
		free(path);
}
