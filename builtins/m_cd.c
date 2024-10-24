/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 11:46:29 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int 	count_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}
char	*my_getenv(char *var_name, t_env *env)
{
	int	j;
	t_env	*tmp;

	if (!var_name)
		return (NULL);
	j = ft_strlen(var_name);
	tmp = env;
	while (tmp)
	{
		if (strncmp(var_name, tmp->key, j) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
	

}
static char	*get_path(t_cmd *cmd, t_env *env, int *verif)
{
	char *path;

	*verif = 0;
	if (count_av(cmd->arg) > 2)
	{
		printf("bash: cd: to many arguments\n");
		return (NULL);
	}
	else if (cmd->arg[1] == NULL || cmd->arg[1] == "~")
		path = my_getenv("HOME", env);
	else if (cmd->arg[1] == "-")
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
	int	verif;

	path = get_path(cmd, env, &verif);
	if (verif == 0)
		return (1);
	if (!path || !chdir(path))
		print_e_cd();
	else if (getcwd(cwd, 1024) != NULL)
	{
		update_env("OLDPWD", my_getenv("PWD", env), env);
		update_env("PWD", cwd, env);
		return (0);
	}
}