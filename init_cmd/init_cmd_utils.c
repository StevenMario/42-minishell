/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:18:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/23 13:52:57 by mrambelo         ###   ########.fr       */
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
	new_cmd->infile = NULL;
	new_cmd->outfile = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*temp;
	t_cmd	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			if (temp->arg)
				ft_free_str(temp->arg);
			if (temp->infile)
				ft_lstclear_file(&temp->infile);
			if (temp->outfile)
				ft_lstclear_file(&temp->outfile);
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}

void ft_print_cmd(t_cmd *cmd)
{
	int i;
	
	while (cmd)
	{
		printf("------------------------\n");
		if (cmd->arg)
		{
			i = -1;
			while (cmd->arg && cmd->arg[++i])
				printf("arg = %s\n",cmd->arg[i]);
		}
		else
			printf("Tsisi arg\n");
		if (cmd->infile )
		{
			printf("===================\n");
			printf("[INFILE]\n");
			printf_infile(cmd->infile);
			printf("===================\n");
		}
		else
			printf("[infile NONE]\n");
		if (cmd->outfile)
		{
			printf("===================\n");
			printf("[OUTFILE]\n");
			printf_infile(cmd->outfile);
			printf("===================\n");
		}
		else
			printf("[outfile NONE]\n");
		cmd = cmd->next;
	}
}
