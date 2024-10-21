/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/21 10:33:38 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	getcmd(t_token *token, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == FILE || token->type == DELIMITER)
		{
			printf("token	: [%s]\n", token->content);
			cmd->arg[i++] = ft_strdup(token->content);
		}
		else
		{
			printf("token add	: [%s]\n", token->content);
			cmd->cmd = ft_strdup(token->content);
		}
	}
}

void	ft_addbackcmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*cmd = new;
	else
		temp->next = new;
}

t_cmd	*ft_initcmd(void)
{
	t_cmd	*new_cmd;


	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->cmd = NULL;
	new_cmd->arg = (char **)malloc(sizeof(char *));
	new_cmd->env = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void new_cmd(t_token *token,t_cmd **cmd)
{
	t_cmd	*new_cmd;

	while (token)
	{
		new_cmd = ft_initcmd();
		if (!new_cmd || !new_cmd->arg)
			return ;
		getcmd(token, new_cmd);
		ft_addbackcmd(cmd, new_cmd);
		token = token->next;
	}
	// if ((*cmd) && (*cmd)->cmd)
	// 	printf("cmd->cmd = %s\n",(*cmd)->cmd);
	// else
	// 	printf("Tsis zavatra\n");
	int i = 0;
	while ((*cmd))
	{
		i = -1;
		if ((*cmd) && (*cmd)->cmd)
			printf("cmd->cmd = %s\n",(*cmd)->cmd);
		while ((*cmd)->arg[++i])
			printf("arg = %s\n",(*cmd)->arg[i]);
		(*cmd) = (*cmd)->next;
	}

}
