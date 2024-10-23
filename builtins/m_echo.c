/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:29:31 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/23 12:38:30 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

static int	iof_flag(char *echo)
{
	int	i;

	i = 0;
	if (echo[0] != '-')
		return (0);
	i++;
	while (echo[i])
	{
		if (echo[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void  ft_echo(char **echo)
{
	int	i;
 	int	option;

 	i = 1;
	option = 0;

	while (echo[i] != NULL && iof_flag(echo[i]) == 1)
	{
		option = 1;
		i++;
	}
	while (echo[i])
	{
		printf("%s", echo[i]);
		if (echo[i + 1])
			printf(" ");
		i++;
	}
	if (option == 0)
		printf("\n");
	return (0);
}
