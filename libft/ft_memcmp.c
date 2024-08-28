/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:12:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	int			delta;
	size_t		i;

	i = 0;
	while (i < size)
	{
		delta = *(const unsigned char *)p1++ - *(const unsigned char *)p2++;
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
