/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:23:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/30 09:25:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char_in_str(char *str,char c)
{
	int i;
	int count;
	
	count = 0;
	i = -1;
	while(str && str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}