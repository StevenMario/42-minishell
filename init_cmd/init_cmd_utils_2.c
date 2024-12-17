/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:13:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 09:47:06 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_cmd	*ft_initcmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->arg = NULL;
	new_cmd->rfile = NULL;
	new_cmd->next = NULL;
	new_cmd->pid = 0;
	new_cmd->status = 0;
	return (new_cmd);
}

void	ft_free_and_close_fd(char *input, int fd)
{
	free(input);
	close(fd);
}
