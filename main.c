/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/08 19:12:20 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int stock_char(t_data *data, char *input,int *i)
{
	int j;
	j = 0;

	while (input[*i])
	{
		while (input[i] == ' ')
			i++;
		j = i;
	}
}

int init_data(t_data *data, char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		while (input[i] != ' ' && input[i] != '|')
			i++;
		stock_char(data, input, &i);
	}
	return 0;
}

int main(int argc,char **argv)
{
	char *input;
	t_data *data;

	(void)argv;
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	while (1)
	{
		input = readline("Minishell_madafucka: ");
 		printf("%s \n",input);
		init_data(data,input);
	}
    return (0);
}