/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/20 15:18:28 by mrambelo         ###   ########.fr       */
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

int	check_redir_type2(int check)
{
	if (check == APPEND || check == INPUT || check == TRUNC
		|| check == HEREDOC)
		return (1);
	return (0);
}
