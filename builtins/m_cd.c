/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/22 16:02:55 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// 2- gestion d'erreur (verifier si le PATH est un dir )
// 3 - make chdir
// 4 - update oldpwd and pwd de env
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
	*verif = 1;
	if (cmd->arg[1] == NULL)
		path = my_getenv("HOME", env);
}
static int 	count_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_cd(t_data *mish, char **prm)
{
	char	*path;
	char	cwd[PATH_MAX];
	int		well_done;

	well_done = 0;
}


