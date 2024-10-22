/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 12:30:41 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void fill_data(t_data *data, char *temp)
{
	temp = ft_remove_front_and_back_space(temp);
	if (data->token == NULL)
				data->token = ft_double_lstnew_token(temp);
		else
			ft_lstadd_back_token(&data->token,ft_double_lstnew_token(temp));
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