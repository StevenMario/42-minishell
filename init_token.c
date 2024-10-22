/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 08:10:50 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void fill_data(t_data *data, char *temp)
{
	temp = ft_remove_front_and_back_space(temp);
	if (data->token == NULL)
				data->token = ft_double_lstnew(temp);
		else
			ft_lstadd_back(&data->token,ft_double_lstnew(temp));
 	free(temp);
 }
char *fill_temp(char *input,int *i,int *j)
{
	char *temp;
	int check;

	temp = NULL;
	check = check_redire(input, i);
	if (input[*i] == '\'' || input[*i] == '"')
	{
		*j = *i;
		(*i)++;
		temp = fill_temp_with_quote(i,j,&temp,input);
	}
	else if (check == PIPE || check == APPEND
		|| check == INPUT || check == TRUNC || check == HEREDOC)
	{
		temp = fill_temp_with_redire(temp, check,i);
		(*i)++;
	}
	else
	{
		*j = *i;
		temp = fill_temp_without_quote(i,j,&temp,input);
	}
	return (temp);
}

void	init_token(t_data *data,char *input)
{
	char *temp;
	int i;
	int j;
	
	i = 0;
	j = 0;
	input = ft_remove_front_and_back_space(input);
	while (input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;
		temp = fill_temp(input,&i,&j);
		fill_data(data,temp);
	}
}