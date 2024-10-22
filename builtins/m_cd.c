/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/22 14:04:31 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// 2- gestion d'erreur (verifier si le PATH est un dir )
// 3 - make chdir
// 4 - update oldpwd and pwd de env
static char	*get_path(t_cmd *cmd, t_env *env)
{
	int	verif;

	verif = 1;
	if ()
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


