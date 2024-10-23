/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/23 13:18:11 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_cmd(t_data *data)
{
	data->cmd = NULL;
	new_cmd(data->token,&data->cmd);
}
void clear_data(t_data *data)
{
	ft_lstclear_cmd(&data->cmd);
	ft_lstclear_token(&data->token);
	free(data);
}
int init_data(t_data *data, char *input)
{	
	data->token = malloc(sizeof(t_token));
	if (!data->token)
		return (0);
	data->token = NULL;
	init_token(data,input);
	assigne_type_token(data);
	// init_cmd(data);
	ft_print_token(data->token);
	// ft_print_cmd(data->cmd);
	// clear_data(data);
	// free(data);
	// ft_print_cmd(data->cmd);
	// <file1 echo>>app test"test" >out.txt<<doc|cat -e "test'hello'" <<heredoc
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
