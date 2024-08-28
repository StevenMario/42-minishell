/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:12:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem_block, int search_value, size_t size)
{
	const char	*cmem_block;
	char		c;
	size_t		i;

	cmem_block = (const char *)mem_block;
	c = (char)search_value;
	i = 0;
	while (i < size)
	{
		if (cmem_block[i] == c)
			return ((char *)cmem_block + i);
		i++;
	}
	return ((char *) NULL);
}
