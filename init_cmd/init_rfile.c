/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:19:49 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/23 13:49:49 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmd.h"

t_file *ft_init_file(void)
{
	t_file *rfile;

	rfile = malloc(sizeof(t_file));
	if (!rfile)
		return (NULL);
	rfile->next = NULL;
	rfile->content = NULL;
	return (rfile);
}

void	ft_add_back_infile(t_file **rfile, t_file *new_file)
{
	t_file	*temp;

	temp = *rfile;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*rfile = new_file;
	else
		temp->next = new_file;
}

void printf_infile(t_file *rfile)
{
	while(rfile)
	{
		if (rfile->type && rfile->content)
			printf("[%d]  [content = %s]\n",rfile->type,rfile->content);
		else
			printf("Tsisi rfile\n");
		rfile = rfile->next;
	}
}

int init_file(t_token *token,t_cmd *cmd)
{
	t_file	*temp;

	temp = ft_init_file();
	if (token->next && (token->type == INPUT || token->type == HEREDOC))
	{
		temp->content = ft_strdup(token->next->content);
		if (token->type == INPUT)
			temp->type = INPUT;
		else
			temp->type = HEREDOC;
		ft_add_back_infile(&cmd->infile, temp);
		return (1);
	}
	else if ((token->next && (token->type == TRUNC || token->type == APPEND)))
	{
		temp->content = ft_strdup(token->next->content);
		if (token->type == TRUNC)
			temp->type = TRUNC;
		else
			temp->type = APPEND;
		ft_add_back_infile(&cmd->outfile, temp);
		return (1);
	}
	return (0);
}
