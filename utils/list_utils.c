/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarantsoa <iarantsoa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:03:26 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/10/15 19:03:27 by iarantsoa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_list(t_lst *lst)
{
	t_lst	*temp;
	int	i;

	if ((lst))
	{
		temp = lst;
		i = 1;
		while (temp->next != lst)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}














