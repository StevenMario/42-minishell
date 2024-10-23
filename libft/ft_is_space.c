/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:07:59 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/23 13:13:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_space(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}