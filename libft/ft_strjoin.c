/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:21:15 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/10 13:45:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	s1_i;
	size_t	s2_i;

	s1_i = ft_strlen(s1);
	s2_i = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_i + 1);
	ft_strlcat(str, s2, s2_i + s1_i + 1);
	free(s1);
	return (str);
}
