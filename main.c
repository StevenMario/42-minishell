/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/12 10:43:26 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	check_and_fill_token(char *line, t_data *data)
// {
// 	int i;
// 	char **split_line = NULL;

// 	i = 0;
// 	(void)data;
// 	while (line[i])
// 	{
// 		split_line = ft_split(line,' ');
// 		i++;
// 	}
// 	i = 0;
// 	while (split_line[i])
// 	{
// 		printf("%s\n",split_line[i]);
// 		i++;
// 	}
// 	return 1;
// }

int	stock_cmd(t_data *data,char **line)
{
	int i;

	i = 0;
	data->cmd = malloc(sizeof(t_cmd));
	while (line[i])
	{
		
		printf("avant line [i] = %s\n",line[i]);
		line[i] = ft_remove_front_and_back_space(line[i]);
		printf("apres line [i] = %s\n",line[i]);
		i++;
	}
	return 0;	
}
int init_data(t_data *data, char *input)
{
	int i;

	i = 0;
	char **line;
	line = ft_split(input, '|');
	while (line[i])
	{
		stock_cmd(data,line);
		//check_and_fill_token(line[i],data);
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
		init_data(data,input);
	}
    return (0);
}