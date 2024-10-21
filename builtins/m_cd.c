/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/16 15:16:41 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// 1- make export
// 2- gestion d'erreur (verifier si le PATH est un dir )
// 3 - make chdir
// 4 - update oldpwd and pwd de env
static int 	count_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static void update_owd(t_data *mish)
{
	t_lst	*temp;
	char	*env_elem;
	int	len;

	temp = mish->e_lst;
	env_elem = NULL;
	len = len_list(tmp);
	while (len--)
	{
		if (ft_strncmp(temp->str, "PWD=", 3) == 0)
			env_elem = temp->s;
		temp = temp->next;
	}
	if (!env_elem)
	{
		export("OLDPWD", &mish->e_lst);
	}
}


int	ft_cd(t_data *mish, char **prm)
{
	int	result;


	if (count_av(prm) == 2)
	{
		res = chdir(prm[1]);
		if (res == 0)
			update_pwd(mish, prm[1]);
		if (res == 1)
			perror(params[1]);
		return (res);
	}
	return (1);
}


