/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:58 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/25 11:09:24 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void printf_rfile(t_file *rfile,int type)
{

		printf("---------------------------------------\n");
		if (type == 1)
			printf("=============INFILE================\n");
		else
			printf("=============OUTFILE================\n");
		while (rfile)
		{
			printf("type = %d\n",type);
			printf("content = %s\n",rfile->content);
			if (rfile->delimiter)
				printf("delimiter = %s\n",rfile->delimiter);
			rfile = rfile->next;
		}
		
}



void herdoc_handler(t_cmd *cmd)
{
	t_file *herdoc;
	t_file *temp;
	
	while (cmd)
	{
		temp = ft_init_file();
		while (cmd->infile)
		{
			if (cmd->infile->type == HEREDOC)
			{
				temp->type = HEREDOC;
				temp->delimiter = ft_strdup(cmd->infile->content);
			}
			if (!herdoc)
				herdoc = temp;
			else
				herdoc->next = temp;
			cmd->infile = cmd->infile->next;
		}
		cmd = cmd->next;
		printf_rfile(herdoc,1);
	}
}