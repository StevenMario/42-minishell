ÉERVGÇ/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:03:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/10 09:03:51 by irabesan         ###   ########.fr       */
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
	
	
}






