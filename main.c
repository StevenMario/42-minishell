/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/13 21:03:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_and_fill_token(char **line, t_data *data)
{
	int i;
	int j;
	char **split_cmd;
	
	i = -1;
	data->token = NULL;
	while (line[++i])
	{
		split_cmd = ft_split(line[i],' ');
		j = -1;
		if (!data->token)
		{
			data->token = ft_double_lstnew(split_cmd[0]);
			j = 0;
		}
		while (split_cmd[++j])
			ft_lstadd_back(&data->token,ft_double_lstnew(split_cmd[j]));
		if (line[i + 1])
			ft_lstadd_back(&data->token,ft_double_lstnew("|"));
		free(split_cmd);
	}
	// while (data->token)
	// {
	// 	printf("data->token->content = %s\n",data->token->content);
	// 	data->token = data->token->next;
	// }
}

void assigne_type_token(t_data *data)
{
	t_token *temp;

	temp = data->token;
	while (temp)
	{
		if (temp->content == '<')
			temp->type = INPUT;
		else if (temp->content == '<<')
			temp->type = HEREDOC;
		else if (temp->content == '>')
			temp->type = TRUNC;
		else if (temp->content == '>>')
			temp->type = APPEND; 
		else if (temp->content == '|')
			temp->type = PIPE; 
	}
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
	assigne_type_token(data);
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