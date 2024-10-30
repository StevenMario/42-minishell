/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:42:11 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/30 11:15:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int check_redire(char *temp,int *i)
{
	if (temp[*i] == '"')
		return (-1);
	else if ((temp[*i] == '>' && temp[*i + 1] == '>'))
		return (APPEND);
	else if ((temp[*i] == '<' && temp[*i + 1] == '<'))		
		return  (HEREDOC);
	else if (temp[*i] == '<')
		return (INPUT);
	else if (temp[*i] == '>')
		return (TRUNC);
	else if (temp[*i] == '|')
		return (PIPE);
	else if (temp[*i] == ' ')
		return (0);
	return (-1);
}

char *fill_temp_with_quote(int *i,int *j,char **temp,char *input)
{
	int x;
	int check_re;
	x = 0;
	while (input[*i] && (input[*i] != '\'' || input[*i] != '"'))
	{
		if (input[*i] == input[*j])
			break;
		(*i)++;
	}
	(*i)++;
	check_re  = check_redire(input,i);
	// printf("check_redire = %d\n",check_re);
	if (check_re == -1)
	{
		while (input[*i] && (check_redire(input,i) == -1))
			(*i)++;
		// printf("Apres input[i] = %c\n",input[*i]);
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
	while ((input[*i] != ' ' && input[*i] != '|'
		&& input[*i] != '>' && input[*i] != '<')&& input[*i])
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

