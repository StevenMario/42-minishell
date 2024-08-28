/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:28:18 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/21 12:34:07 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchChar)
{
	int		i;
	char	letter;

	i = 0;
	letter = (char)searchChar;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] == letter)
			return ((char *)str + i);
		i++;
	}
	if (((char *)str)[i] == '\0' && searchChar == '\0')
		return ((char *)str + i);
	return (0);
}
