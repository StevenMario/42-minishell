/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/01 09:12:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void add_content(char *temp,t_data *data)
{
			if ((temp[0] == '>' && temp[1] == '>'))
			{
				ft_lstadd_back(&data->token,ft_double_lstnew(">>"));
				ft_lstadd_back(&data->token,ft_double_lstnew(temp + 2));
			}
			else if (temp[0] == '<' && temp[1] == '<')
			{
				ft_lstadd_back(&data->token,ft_double_lstnew("<<"));
				ft_lstadd_back(&data->token,ft_double_lstnew(temp + 2));
			}
			else if (temp[0] == '>')
			{
				ft_lstadd_back(&data->token,ft_double_lstnew(">"));
				ft_lstadd_back(&data->token,ft_double_lstnew(temp + 2));
			}
			else if (temp[0] == '<')
			{
				ft_lstadd_back(&data->token,ft_double_lstnew("<"));
				ft_lstadd_back(&data->token,ft_double_lstnew(temp + 2));
			}
			else if (temp[0] == '|')
			{
				ft_lstadd_back(&data->token,ft_double_lstnew("|"));
				ft_lstadd_back(&data->token,ft_double_lstnew(temp + 1));
			}
}

void fill_data(char **split_temp, char *temp,t_data *data)
{
	int i;

	if (temp[0] == '|' || split_temp || temp[0] == '>'
	|| temp[0] == '<' || (temp[0] == '>' && temp[1] == '>') 
	|| (temp[0] == '<' && temp[1] == '<'))
		{
			add_content(temp,data);
			if (split_temp)
			{
				i = -1;
				while (split_temp[++i])
				{
					ft_lstadd_back(&data->token,ft_double_lstnew(split_temp[i]));
					if (split_temp[i + 1])
						ft_lstadd_back(&data->token,ft_double_lstnew("|"));
					if (!split_temp[i + 1] && i < 1)
						ft_lstadd_back(&data->token,ft_double_lstnew("|"));
				}
			}
		}
		else
			ft_lstadd_back(&data->token,ft_double_lstnew(temp));
}

void fill_token(t_data *data, char *temp)
{
	int i;
	int check_pipe;
	char **split_temp;
	
	i = -1;
	(void)data;
	split_temp = NULL;
	check_pipe = 0;
	while (temp[++i])
	{
		if (temp[i] == '"')
			break ;
		else if (temp[i] == '|' && i != 0)
			check_pipe++;
	}
	if (check_pipe > 0 && temp[0] != '|')
		split_temp = ft_split(temp,'|');
	if (data->token == NULL)
		data->token = ft_double_lstnew(temp);
	else
	{
		fill_data(split_temp,temp,data);
	}
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
		if (input[i] == '\'' || input[i] == '"')
		{
			j = i;
			i++;
			temp = fill_temp_with_quote(&i,&j,&temp,input);
		}
		else
		{
			j = i;
			temp = fill_temp_without_quote(&i,&j,&temp,input);
		}
		fill_token(data,temp);	
	}
	return 0;
}

int init_data(t_data *data, char *input)
{
	char **line;

	data->token = NULL;
	if (check_quote(input) == 1)
	{
		init_token_with_quote(data,input);
		assigne_type_token(data);
	}
	else
	{
		line = ft_split(input, '|');
		init_token(data,line);
	}
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
		//check_error(input);
		init_data(data,input);
	}
    return (0);
}
