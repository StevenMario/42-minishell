/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/19 22:09:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_token_with_quote(t_data *data,char *input)
{
	char *line;
	char **stock_line;
	int i;
	(void)data;

	i = 0;
	line = ft_remove_front_and_back_space(input);
	while (line[i])
	{

	}
	return 0;
}

int init_data(t_data *data, char *input)
{
	char **line;
	
	if (!check_quote(input))
	{
		line = ft_split(input, '|');
		init_token(data,line);
	}
	else
	{
		init_token_with_quote(data,input);
	}
	// while (data->token)
	// {
	// 	printf("data->token->content = %s  type == %d\n",data->token->content,data->token->type);
	// 	data->token = data->token->next;
	// }
	return 0;
}

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