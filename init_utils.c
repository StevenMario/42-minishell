/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:42:11 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/09 22:53:55 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_redire(char *temp)
{
	int i;
	
	i = -1;
	while (temp[++i])
	{
		if (temp[i] == '"')
			break ;
		else if (temp[i] == '|')
			return (PIPE);
		else if ((temp[i] == '>' && temp[i + 1] == '>'))
			return (APPEND);
		else if ((temp[i] == '<' && temp[i + 1] == '<'))		
			return  (HEREDOC);
		else if (temp[i] == '<')
			return (INPUT);
		else if (temp[i] == '>')
			return (TRUNC);
	}
	return (-1);
}

char *fill_temp_with_quote(int *i,int *j,char **temp,char *input)
{
	int x;

	x = 0;
	while (input[*i] && (input[*i] != '\'' || input[*i] != '"'))
	{
		if (input[*i] == '\'' || input[*i] == '"')
			break;
		(*i)++;
	}
	*temp = malloc(sizeof(char) * (*i - *j + 1));
	while (*j <= *i)
	{
		(*temp)[x] = input[*j];
		x++;
		(*j)++;
	}
	(*i)++;
	(*temp)[x] = '\0';
	return (*temp);
}

char *fill_temp_without_quote(int *i,int *j,char **temp,char *input)
{
	int	k;
	int x;

	x = 0;
	while (input[*i] != ' ' && input[*i])
		(*i)++;
	k = *i;
	*temp = malloc(sizeof(char) * (k - *j + 1));
	if (!*temp)
		return (NULL);
	while (*j < k)
	{
		(*temp)[x] = input[*j];
		x++;
		(*j)++;
	}
	(*temp)[x] = '\0';
	return (*temp);
}
