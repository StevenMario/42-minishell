/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigne_type_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:26:05 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/21 11:32:07 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_not_arg_or_cmd(char *content)
{
	if (ft_strcmp(content,"<") == 0)
		return (INPUT);
	else if (ft_strcmp(content,"<<") == 0)
		return (HEREDOC);
	else if (ft_strcmp(content,">") == 0)
		return  (TRUNC);
	else if (ft_strcmp(content,">>") == 0)
		return  (APPEND); 
	else if (ft_strcmp(content,"|") == 0)
		return  (PIPE);
	else
		return (-1);
}


int	check_type(t_token *temp)
{
	if (is_not_arg_or_cmd(temp->content) == -1)
	{
		if ((temp->prev && (temp->prev->type == CMD || temp->prev->type == ARG))
			&& (temp->next && is_not_arg_or_cmd(temp->next->content) == -1))
			return (ARG);
		if (((temp->next && is_not_arg_or_cmd(temp->next->content) == -1)) 
 			|| (temp->prev && ft_strcmp(temp->prev->content, "|") == 0)
			|| !temp->prev )
		return CMD;
		if (temp->prev && (ft_strcmp(temp->prev->content, "<") == 0 
			|| ft_strcmp(temp->prev->content, ">>") == 0 
			|| ft_strcmp(temp->prev->content, ">") == 0 ))
			return FILE;
		if (temp->prev && (ft_strcmp(temp->prev->content, "<<") == 0))
			return DELIMITER;
	}
	return (-1);
}

void	ft_is_arg_or_cmd(t_token *temp)
{
	if (is_not_arg_or_cmd(temp->content) == -1)
	{
		if (check_type(temp) == CMD)
			temp->type = CMD;
		else if (check_type(temp) == FILE)
            temp->type = FILE;
        else if (check_type(temp) == DELIMITER)
            temp->type = DELIMITER;
        else
			temp->type = ARG;
	}
}

void assigne_type_token(t_data *data)
{
	t_token *temp;

	temp = data->token;
	while (temp)
	{
		if (is_not_arg_or_cmd(temp->content) == INPUT)
			temp->type = INPUT;
		else if (is_not_arg_or_cmd(temp->content) == HEREDOC)
			temp->type = HEREDOC;
		else if (is_not_arg_or_cmd(temp->content) == TRUNC)
			temp->type = TRUNC;
		else if (is_not_arg_or_cmd(temp->content) == APPEND)
			temp->type = APPEND; 
		else if (is_not_arg_or_cmd(temp->content) == PIPE)
			temp->type = PIPE;
		else
			ft_is_arg_or_cmd(temp);
		temp = temp->next;
	}
}