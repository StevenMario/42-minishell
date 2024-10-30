/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:42:11 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/30 13:21:26 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int check_redire(char *temp,int i)
{
	// if (temp[i] == '"')
	// 	return (-2);
	 if ((temp[i] == '>' && temp[i + 1] == '>'))
		return (APPEND);
	else if ((temp[i] == '<' && temp[i + 1] == '<'))		
		return  (HEREDOC);
	else if (temp[i] == '<')
		return (INPUT);
	else if (temp[i] == '>')
		return (TRUNC);
	else if (temp[i] == '|')
		return (PIPE);
	else if (temp[i] == ' ')
		return (0);
	return (-1);
}

char *stock_char(int *i,int *j,char *input)
{
	char *temp;
	int		x;

	temp = NULL;
	x = 0;
	temp = malloc(sizeof(char) * (*i - *j + 1));
	while (*j <= *i)
	{
		temp[x] = input[*j];
		x++;
		(*j)++;
	}
	(*i)++;
	temp[x] = '\0';
	return (temp);
}

char *fill_temp_with_quote(int *i,int *j,char *input)
{
	int x;
	char *temp;

	x = 0;
	temp = NULL;
	while (input && input[*i] && (input[*i] != '\'' || input[*i] != '"'))
	{
		if (input[*i] == input[*j])
			break;
		(*i)++;
	}
	while (input && input[*i])
	{
		if (check_redire(input,*i + 1) != -1)
			break;
		(*i)++;
	}
	temp = stock_char(i, j,input);
	return (temp);
}

char *fill_temp_without_quote(int *i,int *j,char *input)
{
	int	k;
	int x;
	char *temp;
	char quote;

	x = 0;
	quote = 0;
	temp = NULL;
	while ((input[*i] != ' ' && input[*i] != '|'
		&& input[*i] != '>' && input[*i] != '<')&& input[*i])
	{
		quote = is_quote(input[*i]);
		if (quote)
		{
			// (*i)++;
			while (input[++(*i)])
			{
				if (input[*i] == quote)
					break;
			}
		}
		(*i)++;
	}
	k = *i;
	k--;
	temp = stock_char(&k, j,input);
	return (temp);
}
char *fill_temp_with_redire(char *temp,int check,int *i)
{
	if (check == PIPE)
		temp = ft_strdup("|");
	if (check == APPEND)
	{
		temp = ft_strdup(">>");
		(*i)++;
	}
	if (check == HEREDOC)
	{
		temp = ft_strdup("<<");
		(*i)++;
	}
	if (check == INPUT)
		temp = ft_strdup("<");
	if (check == TRUNC)
		temp = ft_strdup(">");
	return (temp);
}

