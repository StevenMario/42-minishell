/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:20:09 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/19 15:46:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (j < size)
	{
		while (src[i] != '\0' && i + j < size - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
		while (src[i] != '\0')
			i++;
	}
	else
	{
		while (src[i] != '\0')
			i++;
		return (i + size);
	}
	return (i + j);
}
/*int main()
{
	const char src[] = "Helo";
	char dest [20]= "World";
	size_t a = ft_strlcat(dest,src, 8);
	//size_t b = strlcat(dest,src, 7);
	
	printf(" %ld ,\n dest = %s",a,dest);
	return 0;
}*/
