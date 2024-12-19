/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/19 19:41:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	init_cmd(t_data *data)
{
	data->cmd = NULL;
	new_cmd(data->token, &data->cmd);
}

void check_null_content(t_token **token)
{
	if (*token && !(*token)->content)
	{
		if (*token && (*token)->next)
			*token = (*token)->next;
	}
}

void	get_cmd(t_token *token, t_cmd *cmd)
{
	static int	i;

	check_null_content(&token);
	if (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == CMD
			|| (check_redir_type(token->type) && token->in_quote == 1))
		{
			if (!cmd->arg)
			{
				cmd->arg = malloc(sizeof(char *) * (get_nb_arg(token) + 1));
				if (!cmd->arg)
					return ;
				cmd->arg[get_nb_arg(token)] = NULL;
				printf("get_nb_arg(token) = %d\n",get_nb_arg(token));
			}
			cmd->arg[i] = ft_strdup(token->content);
			printf("cmd->arg[i] = %s   i = [%d]\n",cmd->arg[i],i);
			i++;
		}
		else
			init_file(token, cmd);
		if (token->next == NULL)
			i = 0;
	}
	else if (token->type == PIPE)
		i = 0;
}

void	new_cmd(t_token *token, t_cmd **cmd)
{
	t_cmd	*new_cmd;

	new_cmd = NULL;
	while (token)
	{
		if (token->next && (token->type == FILES || token->type == DELIMITER))
			token = token->next;
		if (new_cmd == NULL)
		{
			new_cmd = ft_initcmd();
			if (!new_cmd)
				return ;
		}
		get_cmd(token, new_cmd);
		if (token->type == PIPE || !token->next)
		{
			ft_add_back_cmd(cmd, new_cmd);
			new_cmd = ft_initcmd();
			if (!new_cmd)
				return ;
		}
		token = token->next;
	}
	ft_lstclear_cmd(&new_cmd);
}
