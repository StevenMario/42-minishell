/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/18 22:45:52 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ceck_quote(char *input)
{
	int quote;
	int i;
	
	i = 0;
	quote == 0;
	
	while (input[i])
	{
		if (input[i] == '\'')
			quote++;
		i++;
	}
	return quote;
}

int init_data(t_data *data, char *input)
{
	char **line;
	check_quote(input);
	line = ft_split(input, '|');
	init_token(data,line);
	while (data->token)
	{
		printf("data->token->content = %s  type == %d\n",data->token->content,data->token->type);
		data->token = data->token->next;
	}
	return 0;
}

// void check_error(char *input)
// {
	
// }

int main(int argc,char **argv)
{
	char *input;
	t_data *data;

	(void)argv;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->token = malloc(sizeof(t_token));
	if (!data->token)
		return (1);
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	while (1)
	{
		input = readline("minishell$: ");
		//check_error(input);
		init_data(data,input);
	}
    return (0);
}