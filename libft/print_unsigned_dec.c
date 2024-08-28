/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:22:10 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:55 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nbr_number(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char		*str_num;
	size_t		digits;

	digits = nbr_number(n);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!(str_num))
		return (NULL);
	*(str_num + digits) = '\0';
	while (digits--)
	{
		*(str_num + digits) = n % 10 + '0';
		n = n / 10;
	}
	return (str_num);
}

int	print_unsigned_dec(unsigned int nbr)
{
	size_t	len;
	char	*str;

	len = 0;
	if (nbr == 0)
	{
		ft_print_char('0');
		return (1);
	}
	else
		str = ft_unsigned_itoa(nbr);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
