/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/24 05:13:33 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	get_cmd(t_token *token, t_cmd *cmd)
{
	static int	i;

	if (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == CMD)
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
			init_file(token,cmd);
		if (token->next == NULL)
			i = 0;	
	}
	else if (token->type == PIPE)
		i = 0;
}

void new_cmd(t_token *token,t_cmd **cmd)
{
	t_cmd	*new_cmd;

	new_cmd = ft_initcmd();
	if (!new_cmd)
		return ;
	while (token)
	{
		if (token->next && (token->type == FILES || token->type == DELIMITER))
			token = token->next;
		get_cmd(token, new_cmd);
		if(token->type == PIPE || !token->next)
		{
			ft_add_back_cmd(cmd, new_cmd);
			new_cmd = ft_initcmd();
			if (!new_cmd)
				return ;
		}
		token = token->next;
	}
}
