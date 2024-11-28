/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/28 13:41:44 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fill_data(t_data *data, char *temp)
{
	char *trim_temp;
	
	trim_temp = ft_strtrim(temp, " \n\t");
	if (trim_temp != NULL)
	{
		if (data->token == NULL)
			data->token = ft_double_lstnew_token(trim_temp);
		else
			ft_lstadd_back_token(&data->token, ft_double_lstnew_token(trim_temp));
		free(trim_temp);
	}
}

char	*fill_temp(char *input, int *i)
{
	char	*temp;
	int		j;
	int		check;

	temp = NULL;
	check = check_redire(input, *i);
	if (input[*i] == '\'' || input[*i] == '"')
	{
		j = *i;
		(*i)++;
		temp = fill_temp_with_quote(i, &j, input);
	}
	else if (check == PIPE || check == APPEND
		|| check == INPUT || check == TRUNC || check == HEREDOC)
	{
		temp = fill_temp_with_redire(temp, check, i);
		(*i)++;
	}
	else
	{
		j = *i;
		temp = fill_temp_without_quote(i, &j, input);
	}
	return (temp);
}

void	init_token(t_data *data, char *input)
{
	char	*temp;
	char *input_temp;
	int		i;

	i = 0;
	input_temp = ft_strtrim(input, " \n\t");
	while (input_temp[i])
	{
		while (input_temp[i] == ' ' && input_temp[i])
			i++;
		temp = fill_temp(input_temp, &i);
		if (ft_is_space(temp))
		{
			free(temp);
			break ;
		}
		fill_data(data, temp);
		free(temp);
	}
	free(input_temp);
	free(input);
}
