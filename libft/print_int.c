/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:26:02 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:37 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
