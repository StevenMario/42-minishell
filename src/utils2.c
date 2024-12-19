/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:14:13 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 15:54:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_token(char *content, int i)
{
	if (((content && content[i] && content[i + 1] && content[i + 2])
			&& (content[i] == '>' && content[i + 1] == '>'
				&& content[i + 2] == '>'))
		|| ((content && content[i] && content[i + 1] && content[i + 2])
			&& (content[i] == '<' && content[i + 1] == '<'
				&& content[i + 2] == '<'))
		|| ((content && content[i] && content[i + 1])
			&& (content[i] == '<' && content[i + 1] == '>'))
		|| ((content && content[i] && content[i + 1])
			&& content[i] == '>' && content[i + 1] == '<'))
	{
		ft_error_writer("syntax error near unexpected token",
			" :pipe or redir\n");
		return (1);
	}
	return (0);
}
