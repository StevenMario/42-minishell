/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/21 22:13:30 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_nb_arg(t_token *token)
{
	int nb_token;

	nb_token = 0;
	while(token &&
		(token->type == ARG || token->type == FILE || token->type == DELIMITER))
	{
		nb_token++;
		token = token->next;
	}
	return (nb_token);
}

void	get_cmd(t_token *token, t_cmd *cmd)
{
	static int	i;

	if (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == FILE || token->type == DELIMITER)
		{
			if (!cmd->arg)
			{
				cmd->arg = (char **)malloc(sizeof(char *) * get_nb_arg(token) + 1);
				if (!cmd->arg)
					return ;
				cmd->arg[get_nb_arg(token)] = NULL;
			}
			cmd->arg[i] = ft_strdup(token->content);
			i++;
		}
		else
		{
			cmd->cmd = ft_strdup(token->content);
			i = 0;
		}
	}
}

void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new)
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
	new_cmd->arg = NULL;
	new_cmd->cmd = NULL;
	new_cmd->env = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void new_cmd(t_token *token,t_cmd **cmd)
{
	t_cmd	*new_cmd;

	new_cmd = ft_initcmd();
	if (!new_cmd)
		return ;
	while (token)
	{
		get_cmd(token, new_cmd);
		if(token->type == PIPE 
			|| !token->next )
		{
			ft_add_back_cmd(cmd, new_cmd);
			new_cmd = ft_initcmd();
			if (!new_cmd)
				return ;
		}
		// if (token->type == HEREDOC)
		// {
		// 	new_cmd = ft_initcmd();
		// 	if (!new_cmd)
		// 		return ;
		// }
		token = token->next;
	}
	int i;
	while ((*cmd))
	{
		i = -1;
		printf("------------------------\n");
		if ((*cmd) && (*cmd)->cmd)
			printf("cmd->cmd = %s\n",(*cmd)->cmd);
		while ((*cmd)->arg[++i])
			printf("arg = %s\n",(*cmd)->arg[i]);
		(*cmd) = (*cmd)->next;
	}

}
