/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:42:11 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/20 21:40:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quote(char *input)
{
	int quote;
	int dquote;
	int i;
	
	i = 0;
	quote = 0;
	dquote = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			quote++;
		if (input[i] == '"')
			dquote++;
		i++;
	}
	if (quote % 2 == 0 || dquote % 2 == 0)
		return (1);
	return 0;
}
