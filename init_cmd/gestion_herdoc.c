/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/27 09:53:32 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void printf_rfile(t_file *rfile)
{

		printf("---------------------------------------\n");
		while (rfile)
		{
			if (rfile->type == HEREDOC || rfile->type == INPUT)
				printf("=============INFILE================\n");
			else
				printf("=============OUTFILE================\n");
			printf(" type = %d\n",rfile->type);
			if (rfile->content)
				printf("content = %s\n",rfile->content);
			rfile = rfile->next;
		}
		
}



void herdoc_handler(t_cmd *cmd)
{	
	while (cmd)
	{
		while (cmd->rfile)
		{
			if (cmd->rfile->type == HEREDOC)
				fill_fd_herdoc(cmd->rfile);
			cmd->rfile = cmd->rfile->next;
		}
		cmd = cmd->next;
	}
}