/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:17:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:17:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchChar)
{
	int		i;
	char	letter;
	char	*s;
	char	*result;

	i = 0;
	letter = (char)searchChar;
	s = (char *)str ;
	result = NULL;
	if (letter == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == letter)
			result = &s[i];
		i++;
	}
	return (result);
}
