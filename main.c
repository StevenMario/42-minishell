/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/12 20:56:32 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_and_fill_token(char **line, t_data *data)
{
	int i;
	char **split_cmd;
	
	(void )data;
	i = 0;
	while (line[i])
	{
		printf("line[i] = %s\n",line[i]);
		split_cmd = ft_split(line[i],' ');
		printf("split_cmd = %s\n",split_cmd[i]);
		//ft_lstadd_back(&data->token,ft_double_lstnew(split_cmd[i]));
		i++;
	}
	//printf("OK\n");
	// while (data->token->content)
	// {
	// 	data->token = data->token->next;
	// }
	return 1;
}

int	stock_cmd(t_data *data,char **line)
{
	int i;

	i = -1;
	data->cmd = malloc(sizeof(t_cmd));
	if (!data->cmd)
		return (0);
	while (line[++i])
		line[i] = ft_remove_front_and_back_space(line[i]);
	check_and_fill_token(line, data);
	return (1);	
}
int init_data(t_data *data, char *input)
{
	char **line;
	line = ft_split(input, '|');
	stock_cmd(data,line);
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