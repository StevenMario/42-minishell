/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:29:05 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/19 18:00:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup_src;
	char	*csrc;

	if (!src)
		return (NULL);
	csrc = (char *)src;
	dup_src = malloc(sizeof(char) *(ft_strlen(csrc) + 1));
	if (!dup_src)
	{
		dup_src = NULL;
		return (0);
	}
	i = 0;
	while (csrc[i] != '\0')
	{
		dup_src[i] = csrc[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}
