/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 14:34:57 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int get_nb_arg(t_token *token)
{
	int nb_token;

	nb_token = 0;
	while(token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == CMD)
			nb_token++;
		token = token->next;
	}
	return (nb_token);
}

void init_file(t_token *token,t_cmd *cmd)
{
	(void)cmd;
	printf("token->content = %s\n",token->content);
}

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
			cmd->arg[i++] = ft_strdup(token->content);
		}
		else 
		{
			printf("Tonga ato\n");
			init_file(token,cmd);
		}
	}
	else if (token->type == PIPE)
		i = 0;
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

t_file *ft_init_file(void)
{
	t_file *rfile;

	rfile = malloc(sizeof(t_file));
	rfile->next = NULL;
	rfile->content = NULL;
	return (rfile);
}

t_cmd	*ft_initcmd(void)
{
	t_cmd	*new_cmd;


	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->arg = NULL;
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
		if(token->type == PIPE || !token->next)
		{
			ft_add_back_cmd(cmd, new_cmd);
			new_cmd = ft_initcmd();
			if (!new_cmd)
				return ;
		}
		token = token->next;
	}
	// int i;
	// while ((*cmd))
	// {
		
	// 	i = -1;
	// 	printf("------------------------\n");
	// 	while ((*cmd)->arg && (*cmd)->arg[++i])
	// 		printf("arg = %s\n",(*cmd)->arg[i]);
	// 	// printf("Misi zavatra\n");
	// 	(*cmd) = (*cmd)->next;
	// }
}
