/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:12:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	total_size;
	char	*byte_ptr;
	void	*ptr;

	total_size = elementCount * elementSize;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		byte_ptr = (char *)ptr;
		while (total_size-- > 0)
			*byte_ptr++ = 0;
	}
	return (ptr);
}
