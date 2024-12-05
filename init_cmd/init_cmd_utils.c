/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:18:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/04 16:46:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	get_nb_arg(t_token *token)
{
	int	nb_token;

	nb_token = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == ARG || token->type == CMD)
			nb_token++;
		token = token->next;
	}
	return (nb_token);
}

t_file	*duplicate_file(t_file *file)
{
	t_file	*new_file;

	new_file = malloc(sizeof(t_file));
	if (!new_file)
		return (NULL);
	if (file->content)
		new_file->content = ft_strdup(file->content);
	new_file->type = file->type;
	new_file->fd = file->fd;
	new_file->next = NULL;
	return (new_file);
}

t_cmd	*duplicate_cmd(t_cmd *cmd)
{
	t_cmd	*new_cmd;
	t_file	*temp;
	int		arg_count;

	temp = NULL;
	new_cmd = ft_initcmd();
	if (!new_cmd)
		return (NULL);
	arg_count = 0;
	while (cmd->arg[arg_count])
		arg_count++;
	new_cmd->arg = malloc((arg_count + 1) * sizeof(char *));
	new_cmd->arg[arg_count] = NULL;
	arg_count = -1;
	while (cmd->arg && cmd->arg[++arg_count])
		new_cmd->arg[arg_count] = ft_strdup(cmd->arg[arg_count]);
	if (cmd->rfile)
	{
		while (cmd->rfile)
		{
			if (!new_cmd->rfile)
				new_cmd->rfile = duplicate_file(cmd->rfile);
			else
			{
				temp = duplicate_file(cmd->rfile);
				ft_add_back_rfile(&new_cmd->rfile, temp);
				ft_lstclear_file(&temp);
			}
			cmd->rfile = cmd->rfile->next;
		}
	}
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*cmd = duplicate_cmd(new);
	else
		temp->next = duplicate_cmd(new);
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*next;

	while ((*lst) != NULL)
	{
		next = (*lst)->next;
		if ((*lst)->arg)
			ft_free_str((*lst)->arg);
		if ((*lst)->rfile)
			ft_lstclear_file(&(*lst)->rfile);
		free((*lst));
		(*lst) = next;
	}
	*lst = NULL;
}
