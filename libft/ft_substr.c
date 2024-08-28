/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:38:22 by mrambelo          #+#    #+#             */
/*   Updated: 2024/02/23 09:38:24 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	str_i;
	unsigned int	s_i;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str_i = 0;
	s_i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[s_i] != '\0')
	{
		if (s_i >= start && str_i < len)
		{
			str[str_i] = s[s_i];
			str_i++;
		}
		s_i++;
	}
	str[str_i] = '\0';
	return (str);
}
