/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:16:53 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/26 17:34:10 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
    {
        // fprintf(stderr, "Libération de '%s'\n", str[i]);
        free(str[i]);
        i++;
    }
    if (str)
    {
        // fprintf(stderr, "Libération du tableau\n");
        free(str);
    }
}
