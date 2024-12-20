/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 12:44:53 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_error_chdir(char *path)
{
	struct stat	sb;

	sb.st_mode = 0;
	lstat(path, &sb);
	if (!path)
		ft_error_writer("cd", " :HOME not set\n");
	else if (access(path, F_OK) == -1)
		ft_error_writer(path, " :no such file or directory\n");
	else if (!S_ISDIR(sb.st_mode))
		ft_error_writer(path, " :is not a directory\n");
	else if (access(path, X_OK) == -1)
		ft_error_writer(path, " :permission denied\n");
	else
		return ;
	if (path)
		free(path);
}

int	count_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static char	*get_path(t_cmd *cmd, t_env *env, int *verif)
{
	char	*path;

	*verif = 0;
	path = NULL;
	if (count_av(cmd->arg) > 2)
	{
		ft_error_writer("cd", " :to many arguments\n");
		return (NULL);
	}
	else if (cmd->arg[1] == NULL || (ft_strcmp(cmd->arg[1], "~") == 0))
		path = my_getenv("HOME", env);
	else if (ft_strcmp(cmd->arg[1], "-") == 0)
		path = my_getenv("OLDPWD", env);
	else
		path = ft_strdup(cmd->arg[1]);
	*verif = 1;
	return (path);
}

int	ft_cd(t_cmd *cmd, t_env *env)
{
	char	*path;
	char	cwd[1024];
	int		verif;
	char	*pwd_update;

	path = NULL;
	path = get_path(cmd, env, &verif);
	if (verif == 0)
		return (1);
	if (!path || (chdir(path) < 0))
	{
		check_error_chdir(path);
		return (1);
	}
	else if (getcwd(cwd, 1024) != NULL)
	{
		pwd_update = my_getenv("PWD", env);
		update_env("OLDPWD", pwd_update, env);
		update_env("PWD", cwd, env);
		free(pwd_update);
	}
	if (path)
		free(path);
	return (0);
}
