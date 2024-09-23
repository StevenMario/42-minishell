/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/23 10:32:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_token_with_quote(t_data *data,char *input)
{
	char *temp;
	int i;
	int j;
	int k;
	int x = 0;
	
	i = 0;
	j = 0;
	(void)data;
	input = ft_remove_front_and_back_space(input);
	while (input[i])
	{
		x = 0;
		
		while (input[i] == ' ' && input[i])
			i++;
		if (input[i] == '\'' || input[i] == '"')
		{
			j = i;
			i++;
			temp = fill_temp(&i,&j,&temp,input);;
		}
		else
		{
			j = i;
			while (input[i] != ' ' && input[i])
				i++;
			k = i;
			temp = malloc(sizeof(char) * (k - j + 1));
			while (j < k)
			{
				temp[x] = input[j];
				x++;
				j++;
			}
			temp[x] = '\0';
		}
		printf("temp = %s\n",temp);
		free(temp);
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
