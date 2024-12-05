/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redire_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:23:17 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/23 01:26:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	redire_handler(t_cmd *cmd)
{
	t_file	*input;
	t_file	*output;

	if (infile)
	{
		while (cmd->infile && open_file(cmd->infile, &input) != -1)
		{
		}
	}
}
