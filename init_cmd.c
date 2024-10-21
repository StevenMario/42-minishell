/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/20 21:32:20 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void new_cmd(t_token *token,t_cmd **cmd)
{
	t_cmd	*new_cmd;
	t_cmd	*temp_cmd;
	t_token *temp;
	int i;

	temp = token;
	(*cmd) = NULL;
	temp_cmd = NULL;
	while (temp)
	{
		new_cmd = malloc(sizeof(t_cmd));
		new_cmd->arg = malloc(sizeof(char *));
		if (!new_cmd || !new_cmd->arg)
			return ;
		i = 0;
		// printf("--------------------------\n");
		while (temp && temp->type != PIPE)
		{
			if (temp->type == CMD || temp->type == INPUT
			|| temp->type == HEREDOC || temp->type == APPEND || temp->type == TRUNC)
			{
				new_cmd->cmd = ft_strdup(temp->content);
				// printf("new->cmd = %s\n",new_cmd->cmd);
			}	
			else
			{
				if (new_cmd->arg[i])
					i++;
				new_cmd->arg[i] = ft_strdup(temp->content);
			}
			temp = temp->next;
		}
		if (!(*cmd))
		{
			(*cmd) = new_cmd;
			temp_cmd = (*cmd);
		}
		else
		{
			if(!temp_cmd->next)
					temp_cmd->next = new_cmd;
			// printf("temp_cmd->cmd = %s\n",temp_cmd->cmd);
			// if ((*cmd)->next && (*cmd)->next->cmd)
			// 	printf("cmd->cmd = %s\n",(*cmd)->next->cmd);
			// temp_cmd = temp_cmd->next;
		}
		if (temp == NULL)
		{
			new_cmd->next = NULL;
			// temp_cmd->next = NULL;
			break;
		}
		// temp_cmd->next = temp_cmd->next->next;
		new_cmd = new_cmd->next;
		temp = temp->next;
	}
	while ((*cmd))
	{
		if ((*cmd) && (*cmd)->cmd)
			printf("cmd->cmd = %s\n",(*cmd)->cmd);
		else
		printf("cmd = Tsisi inonnina\n");
		if((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else	
			break;
	}

}
