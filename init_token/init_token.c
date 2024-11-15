/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/15 08:57:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fill_data(t_data *data, char *temp)
{
	temp = ft_strtrim(temp, " \n\t");
	if (temp != NULL)
	{
		if (data->token == NULL)
			data->token = ft_double_lstnew_token(temp);
		else
			ft_lstadd_back_token(&data->token, ft_double_lstnew_token(temp));
		free(temp);
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
	int		i;

	i = 0;
	input = ft_strtrim(input, " \n\t");
	while (input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;
		temp = fill_temp(input, &i);
		if (ft_is_space(temp))
		{
			free(temp);
			break ;
		}
		fill_data(data, temp);
	}
	free(input);
}
