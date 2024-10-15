/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/15 09:57:50 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void fill_data(t_data *data, char *temp)
{
	temp = ft_remove_front_and_back_space(temp);
	if (data->token == NULL)
				data->token = ft_double_lstnew(temp);
		else
			ft_lstadd_back(&data->token,ft_double_lstnew(temp));
 	free(temp);
 }
int	init_token_with_quote(t_data *data,char *input)
{
	char *temp;
	int i;
	int j;
	
	i = 0;
	j = 0;
	input = ft_remove_front_and_back_space(input);
	while (input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;
		temp = fill_temp(input,&i,&j);
		fill_data(data,temp);
	}
	return 0;
}

int init_data(t_data *data, char *input)
{	
	data->token = NULL;
	init_token_with_quote(data,input);
	assigne_type_token(data);
	while (data->token)
	{
		printf("data->token->content = %s  type == %d\n",data->token->content,data->token->type);
		data->token = data->token->next;
	}
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
		init_data(data,input);
	}
    return (0);
}
