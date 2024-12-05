/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:00:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/05 12:54:36 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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

char	**env_to_2d(t_env *env)
{
	char	**arr;
	int		j;

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

char	*ft_test_access(char **path_spl, char *cmd)
{
	char	*join_path;
	int		i;

	i = -1;
	while (path_spl[++i])
	{
		join_path = double_join_env1(path_spl[i], cmd);
		if (join_path && access(join_path, F_OK) == 0)
			return (join_path);
		if (join_path)
			free(join_path);
	}
	if (join_path)
		free(join_path);
	return (NULL);
}

int	exec_extern_cmd(t_env *env, t_cmd *cmd)
{
	char	**env_2d;
	char	**path_spl;
	char	*path;

	env_2d = env_to_2d(env);
	path_spl = split_for_path(env);
	if (ft_strchr(cmd->arg[0], '/'))
		path = ft_strdup(cmd->arg[0]);
	else
		path = ft_test_access(path_spl, cmd->arg[0]);
	if (path == NULL)
	{
		printf("minishell: %s: command not found\n", cmd->arg[0]);
		ft_free_env2d_pathspl(env_2d, path_spl, path);
		return (0);
	}

	if (access(path, X_OK) != 0)
	{
		printf("minishell: %s: permission denied\n", cmd->arg[0]);
		ft_free_env2d_pathspl(env_2d, path_spl, path);
		return (0);
	}
	execve(path, cmd->arg, env_2d);
	ft_free_env2d_pathspl(env_2d, path_spl, path);
	return (1);
}
