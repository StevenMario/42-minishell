/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:06:15 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/05 08:37:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	print_exit_and_free(t_data *mish, int status)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	clear_data(mish);
	exit(status);
}
