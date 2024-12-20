/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/20 16:22:21 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

char	**remove_quote_no_expand(char *trim_temp)
{
	char	**expand_val;

	expand_val = malloc(sizeof(char *) * 2);
	if (!expand_val)
		return (NULL);
	expand_val[0] = remove_quote_process(trim_temp);
	expand_val[1] = NULL;
	return (expand_val);
}

int	check_last_token_is_herrdoc(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp && tmp->content && ft_strcmp(tmp->content, "<<") == 0)
		return (1);
	return (0);
}

void	fill_data(t_data *data, char *temp)
{
	t_tk	tk;

	tk.status = 0;
	tk.is_expand = 0;
	tk.expand_val = NULL;
	tk.trim_temp = ft_strtrim(temp, " \n\t");
	if (ft_count_char_in_str(tk.trim_temp, '$')
		&& !check_last_token_is_herrdoc(data->token))
	{
		tk.expand_val = check_var(tk.trim_temp, data->e_lst);
		tk.is_expand = 1;
	}
	else
	{
		tk.expand_val = remove_quote_no_expand(tk.trim_temp);
		if (ft_count_char_in_str(tk.trim_temp, '\'') > 0
			|| ft_count_char_in_str(tk.trim_temp, '"') > 0)
			tk.status = 1;
	}
	free(tk.trim_temp);
	add_token(data, tk);
	if (tk.expand_val)
		ft_free_str(tk.expand_val);
}

char	*fill_temp(char *input, int *i)
{
	char	*temp;
	int		j;
	int		check;

	temp = NULL;
	check = check_redire(input, *i);
	if (input[*i] && (input[*i] == '\'' || input[*i] == '"'))
	{
		j = *i;
		(*i)++;
		temp = fill_temp_with_quote(i, &j, input);
		if (input[*i] && input[(*i) + 1])
			(*i)++;
	}
	else if (check_redir_type(check))
		temp = fill_temp_with_redire(temp, check, i, input);
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
	assigne_type_token(data);
}
