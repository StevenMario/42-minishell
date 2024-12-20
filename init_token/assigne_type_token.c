/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigne_type_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:26:05 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/20 15:57:17 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	is_not_arg_or_cmd(t_token *token)
{
	if (token)
	{
		if (ft_strcmp(token->content, "<") == 0)
			return (INPUT);
		else if (ft_strcmp(token->content, "<<") == 0)
			return (HEREDOC);
		else if (ft_strcmp(token->content, ">") == 0)
			return (TRUNC);
		else if (ft_strcmp(token->content, ">>") == 0)
			return (APPEND);
		else if (ft_strcmp(token->content, "|") == 0)
			return (PIPE);
	}
	return (-1);
}

int	check_type(t_token *temp)
{
	if (is_not_arg_or_cmd(temp) == -1)
	{
		if (temp->prev && (temp->prev->type == INPUT
				|| temp->prev->type == APPEND || temp->prev->type == TRUNC))
			return (FILES);
		if (temp->prev && temp->prev->type == HEREDOC)
			return (DELIMITER);
		if ((temp->prev && (temp->prev->type == CMD
					|| temp->prev->type != PIPE)) && (temp->next
				&& is_not_arg_or_cmd(temp) == -1))
			return (ARG);
		if (((temp->next && is_not_arg_or_cmd(temp) == -1)) || (temp->prev
				&& (temp->prev->type == PIPE)) || !temp->prev)
			return (CMD);
	}
	return (-1);
}

void	ft_is_arg_or_cmd(t_token *temp)
{
	if (is_not_arg_or_cmd(temp) == -1)
	{
		if (check_type(temp) == CMD)
			temp->type = CMD;
		else if (check_type(temp) == FILES)
			temp->type = FILES;
		else if (check_type(temp) == DELIMITER)
			temp->type = DELIMITER;
		else
			temp->type = ARG;
	}
}

int	is_redire(int *tmp_type, t_token *temp)
{
	if (is_not_arg_or_cmd(temp) == INPUT)
	{
		*tmp_type = INPUT;
		return (1);
	}
	else if (is_not_arg_or_cmd(temp) == HEREDOC)
	{
		*tmp_type = HEREDOC;
		return (1);
	}
	else if (is_not_arg_or_cmd(temp) == TRUNC)
	{
		*tmp_type = TRUNC;
		return (1);
	}
	else if (is_not_arg_or_cmd(temp) == APPEND)
	{
		*tmp_type = APPEND;
		return (1);
	}
	return (0);
}

void	assigne_type_token(t_data *data)
{
	t_token	*temp;

	temp = data->token;
	while (temp)
	{
		if (temp && temp->prev && temp->prev->type == HEREDOC
			&& ft_strcmp(temp->content, "|") != 0)
			temp->type = DELIMITER;
		else if (temp->is_expand == 1 || temp->in_quote == 1)
			temp->type = ARG;
		else if (is_not_arg_or_cmd(temp) != -1 && temp->in_quote)
			temp->type = ARG;
		else if (is_redire(&temp->type, temp))
		{
		}
		else if (is_not_arg_or_cmd(temp) == PIPE)
			temp->type = PIPE;
		else
			ft_is_arg_or_cmd(temp);
		temp = temp->next;
	}
}
