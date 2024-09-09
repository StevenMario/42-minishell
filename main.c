/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/09 13:22:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_and_fill_token(char *line, t_data **data)
{
	int i;
	int check_pipe;
	char **split_line;

	i = 0;
	check_pipe = 0;
	while (line[i])
	{
		if (line[i] == '|')
			check_pipe++;
		i++;
	}
	i = 0;
	if (check_pipe > 0)
	{
		split_line = ft_split(line,'|');
		while (split_line[i])
		{
			*data->token->content = ft_strdup(split_line[i]);
			*data->token->next
		}
	}
}

int init_data(t_data *data, char *input)
{
	int i;

	i = 0;
	char **line;
	line = ft_split(input, ' ');
	while (line[i])
	{
		check_and_fill_token(line[i],data);
		i++;
	}
	return 0;
}

int main(int argc,char **argv)
{
	char *input;
	t_data *data;

	(void)argv;
	data = malloc(sizeof(t_data));
	data->token = malloc(sizeof(t_token));
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	while (1)
	{
		input = readline("minishell$: ");
 		printf(" input = %s \n",input);
		init_data(data,input);
	}
    return (0);
}