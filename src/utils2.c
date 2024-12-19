/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:14:13 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 13:07:37 by mrambelo         ###   ########.fr       */
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

int	loop_check_valid_token(char *str, int *exit_status)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (check_valid_token(str, i) == 1)
		{
			free(str);
			*exit_status = 2;
			return (1);
		}
	}
	return (0);
}

// int  check_in_quote(char *str)
// {
// 	int len;

// 	len = ft_strlen(str);
// 	if (str)
// 	{
// 		if ((str[0] == '"' && str[len - 1] == '"')
// 		|| (str[0] == '\'' && str[len - 1] == '\''))
// 			return (1);
// 	}
// }
