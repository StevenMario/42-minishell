/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 09:45:28 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	check_redir_type(int check)
{
	if (check == PIPE || check == APPEND || check == INPUT || check == TRUNC
		|| check == HEREDOC)
		return (1);
	return (0);
}
