/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/17 21:51:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void new_cmd(t_token *token,t_cmd *cmd)
{
	t_cmd	*new_cmd;
	t_token *temp;
	int i;

	temp = token;
	new_cmd = cmd;
	while (temp)
	{
		new_cmd = malloc(sizeof(t_cmd));
		new_cmd->arg = malloc(sizeof(char *));
		if (!new_cmd)
			return ;
		i = 0;
		printf("--------------------------\n");
		while (temp && temp->type != PIPE)
		{
			if (temp->type == CMD || temp->type == INPUT
			|| temp->type == HEREDOC || temp->type == APPEND || temp->type == TRUNC)
			{
				new_cmd->cmd = ft_strdup(temp->content);
				printf("cmd = %s\n",new_cmd->cmd);
			}	
			else
			{
				if (new_cmd->arg[i])
					i++;
				new_cmd->arg[i] = ft_strdup(temp->content);
				printf("arg = %s\n",new_cmd->arg[i]);
			}
			temp = temp->next;
		}
		if (temp == NULL)
			break;
		new_cmd = new_cmd->next;
		temp = temp->next;
	}
	// while (cmd)
	// {
	// 	if (cmd->cmd)
	// 		printf("cmd = %s\n",cmd->cmd);
	// 	if (cmd->arg)
	// 	{
	// 		i = 0;
	// 		while (cmd->arg[i])
	// 		{
	// 			printf("arg = %s\n",cmd->arg[i]);
	// 			i++;
	// 		}
	// 	}
	// 	cmd = cmd->next;
	// }
}
