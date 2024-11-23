/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/15 09:37:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	if (count_av(cmd->arg) > 2)
	{
		printf("Minishell: cd: to many arguments\n");
		return (NULL);
	}
	else if (cmd->arg[1] == NULL || (ft_strcmp(cmd->arg[1], "~") == 0))
		path = my_getenv("HOME", env);
	else if (ft_strcmp(cmd->arg[1], "-") == 0)
		path = my_getenv("OLDPWD", env);
	else
		path = cmd->arg[1];
	*verif = 1;
	return (path);
}

int	ft_cd(t_cmd *cmd, t_env *env)
{
	char	*path;
	char	cwd[1024];
	int		verif;

	path = get_path(cmd, env, &verif);
	if (verif == 0)
		return (1);
	if (!path || (chdir(path) < 0))
		return (1);
	else if (getcwd(cwd, 1024) != NULL)
	{
		update_env("OLDPWD", my_getenv("PWD", env), env);
		update_env("PWD", cwd, env);
	}
	return (0);
}
