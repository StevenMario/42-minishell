/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/10 12:44:48 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fill_data(t_data *data, char *temp)
{
	char	*trim_temp;
	char	**expand_val;
	int i;

	i = -1;
	trim_temp = ft_strtrim(temp, " \n\t");
	if (ft_count_char_in_str(trim_temp,'$'))
		expand_val = check_var(trim_temp, data->e_lst);
	else
	{
		expand_val = malloc(sizeof(char *) * 2);
		expand_val[0] = ft_strdup(trim_temp);
		expand_val[1] = NULL;
	}	
	free(trim_temp);	
	while (expand_val[++i])
	{
		if (data->token == NULL)
			data->token = ft_double_lstnew_token(expand_val[i]);
		else
			ft_lstadd_back_token(&data->token,
				ft_double_lstnew_token(expand_val[i]));
	}
}

char	*fill_temp(char *input, int *i)
{
	char	*temp;
	int		j;
	int		check;

	temp = NULL;
	check = check_redire(input, *i);
	if (input[*i] && ( input[*i] == '\'' || input[*i] == '"'))
	{
		j = *i;
		(*i)++;
		temp = fill_temp_with_quote(i, &j, input);
		if (input[*i] && input[(*i) + 1])
			(*i)++;
	}
	else if (check == PIPE || check == APPEND || check == INPUT
		|| check == TRUNC || check == HEREDOC)
	{
		temp = fill_temp_with_redire(temp, check, i);
		if (input[*i] && input[(*i) + 1])
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
	char	*input_temp;
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
