/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:58:07 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/29 08:21:11 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_arg_is_nbr(char *arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}
static void	handling_ss(char *arg, int *i, int *sign)
{
	while (arg[*i] && arg[*i] == ' ')
		(*i)++;
	if (arg[*i] == '+' || arg[*i] == '-')
	{
		if (arg[*i] == '-')
			*sign *= -1;
		*i++;
	}
}
int	ft_exit(t_cmd *cmd)
{
	
}