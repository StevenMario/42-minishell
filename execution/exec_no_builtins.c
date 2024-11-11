/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:00:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/06 13:00:36 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char **split_for_path(t_env *env)
{
	char **arr;
	char *content;

	arr = NULL;
	content = my_getenv("PATH", env);
	if (!env || content == NULL)
		return (NULL);
	arr = ft_split(content, ':');
	if (!arr)
		return (NULL);
	return (arr);
}

char *ft__join_env(char *s1, char *s2)
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

char	*double_join_env(char *s1, char *s2)
{
	char	*r1;

	if (!s1)
		return (NULL);
	r1 = ft__join_env(s1, "=");
	if (!r1)
		return (NULL);
	r1 = ft_strjoin(r1, s2);
	if (!r1)
		return (NULL);
	return (r1);
}

char **env_to_2d(t_env *env)
{
	char	**arr;
	int	j;

	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_env_len(env) + 1));
	while (env)
	{
		if (env->key && env->value)
			arr[j] = double_join_env(env->key, env->value);
		env = env->next;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
int	ft_test_access(char *path)
{
	if (path)
	{
		if (!access(path, F_OK))
		{
			printf("mininshell: ls: command not found\n");
			return (1);	
		}
		if (!access(path, X_OK))
		{
			printf("mininshell: ls: permission denied\n");
			return (1);	
		}

	}
	return (0);
}
int	exec_extern_cmd(t_env *env, t_cmd *cmd)
{
	char **env_2d;
	char	**path_spl;
	char	*join_path;
	int	i;

	i = -1;
	env_2d = env_to_2d(env);
	path_spl = split_for_path(env);
	while (path_spl[++i])
	{
		join_path = ft__join_env(path_spl[i], cmd->arg[0]);
		if (ft_test_access(join_path) == 0)
		{
			execve(join_path, cmd->arg, env_2d);
			return (0);
		}
		free(join_path);
	}
	return (1);
}
