/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/30 10:28:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void fill_data(t_data *data, char *temp)
{
	temp = ft_remove_front_and_back_space(temp);
	if (temp != NULL)
	{
		if (data->token == NULL)
					data->token = ft_double_lstnew_token(temp);
		else
				ft_lstadd_back_token(&data->token,ft_double_lstnew_token(temp));
 		free(temp);
	}
 }
char *fill_temp(char *input,int *i)
{
	char *temp;
	int		j;
	int 	check;

	temp = NULL;
	// j = *i;
	if (input && input[*i] && (check_redire(input,*i) == -1))
	{
		j = *i;
		(*i)++;
		temp = fill_temp_with_quote(i,&j,&temp,input);
	}
	else if (check == PIPE || check == APPEND
		|| check == INPUT || check == TRUNC || check == HEREDOC)
	{
		temp = fill_temp_with_redire(temp, check,i);
		(*i)++;
	}
	else
	{
		j = *i;
		temp = fill_temp_without_quote(i,&j,&temp,input);
	}
	return (temp);
}

void	init_token(t_data *data,char *input)
{
	char *temp;
	int i;
	
	i = 0;
	(void)data;
	input = ft_strtrim(input, " ");
	while (input && input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;
		fill_temp(input, &i);
		if (temp && ft_is_space(temp))
		{
			free(temp);
			break;
		}
		fill_data(data,temp);
		i++;
	}
	free(input);
}