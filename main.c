/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/16 09:11:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_cmd(t_data *data)
{
	new_cmd(data->token,data->cmd);
}

int init_data(t_data *data, char *input)
{	
	data->token = malloc(sizeof(t_token));
	if (!data->token)
		return (0);
	data->token = NULL;
	init_token(data,input);
	assigne_type_token(data);
	init_cmd(data);
	return 1;
}

int main(int argc,char **argv)
{
	char *input;
	t_data *data;

	(void)argv;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	while (1)
	{
		input = readline("minishell$: ");
		if (!init_data(data,input))
			return (1);
	}
    return (0);
}
