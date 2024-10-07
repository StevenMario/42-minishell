/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/07 19:11:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void add_content(t_data *data, int check,char **split_temp,int *i)
{
	if (!split_temp[*i + 1] && *i < 1 && check == PIPE)
		ft_lstadd_back(&data->token,ft_double_lstnew("|"));
	else if (!split_temp[*i + 1] && *i < 1 && check == TRUNC)
		ft_lstadd_back(&data->token,ft_double_lstnew(">"));
	else if (!split_temp[*i + 1] && *i < 1 && check == INPUT)
		ft_lstadd_back(&data->token,ft_double_lstnew("<"));
	else if (!split_temp[*i + 1] && *i < 1 && check == APPEND)
		ft_lstadd_back(&data->token,ft_double_lstnew(">>"));
	else if (!split_temp[*i + 1] && *i < 1 && check == HEREDOC)
		ft_lstadd_back(&data->token,ft_double_lstnew("<<"));
}


int check_redire(char *temp)
{
	int check_simple;
	int check_double;
	int i;

	i = -1;
	check_simple = 0;
	check_double = 0;
	while (temp[++i])
	{
		if ((temp[i] == '>' && temp[i + 1] == '>'))
			check_double++;
		else if ((temp[i] == '>' || temp[i] == '<'))
			check_simple++;
	}
	if (check_double)
		return (1);
	else if (check_simple)
		return (2);
	return (0);
}
void check_and_fill_redire(t_data *data, int check,char **split_temp,int *i)
{
	printf("check = %d\n",check);
	if (split_temp[*i + 1] && check == PIPE)
		ft_lstadd_back(&data->token,ft_double_lstnew("|"));
	else if (split_temp[*i + 1] && check == INPUT)
		ft_lstadd_back(&data->token,ft_double_lstnew("<"));
	else if (split_temp[*i + 1] && check == TRUNC)
		ft_lstadd_back(&data->token,ft_double_lstnew(">"));
	else if (split_temp[*i + 1] && check == APPEND)
		ft_lstadd_back(&data->token,ft_double_lstnew(">>"));
	else if (split_temp[*i + 1] && check == HEREDOC)
		ft_lstadd_back(&data->token,ft_double_lstnew("<<"));
}

void fill_data(char **split_temp, char *temp,t_data *data,int check)
{
	int i;

	if (temp[0] == '|' || split_temp || temp[0] == '>'
	|| temp[0] == '<' || (temp[0] == '>' && temp[1] == '>') 
	|| (temp[0] == '<' && temp[1] == '<'))
		{
			if (split_temp)
			{
				i = -1;
				while (split_temp[++i])
				{
					
					add_content(data, check,split_temp, &i);
					ft_lstadd_back(&data->token,ft_double_lstnew(split_temp[i]));
					check_and_fill_redire(data,check,split_temp,&i);
				}
			}
		}
		else
			ft_lstadd_back(&data->token,ft_double_lstnew(temp));
}

char **fill_split_temp(char *temp ,int check)
{
	char **split_temp;
	
	split_temp = NULL;
	if (check == PIPE)
		split_temp = ft_split(temp,'|');
	else if (check == INPUT || check == HEREDOC)
		split_temp = ft_split(temp,'<');
	else if (check == TRUNC || check == APPEND)
		split_temp = ft_split(temp,'>');
	else 
		return (NULL);
	return split_temp;
}

void fill_token(t_data *data, char *temp)
{
	int i;
	int check;
	char **split_temp;
	
	i = -1;
	split_temp = NULL;
	check = 0;
	while (temp[++i])
	{
		if (temp[i] == '"')
			break ;
		else if ((temp[i] == '>' && temp[i + 1] == '>'))
		{
			check = APPEND;
			break;
		}	
		else if ((temp[i] == '<' && temp[i + 1] == '<'))		
		{
			check = HEREDOC;
			break;
		}	
		else if (temp[i] == '<')
			check = INPUT;
		else if (temp[i] == '>')
			check = TRUNC;
		else if (temp[i] == '|')
			check = PIPE;
	}
	if (check > -1)
	{
		split_temp = fill_split_temp(temp ,check);	
		
	}
	if (data->token == NULL)
		data->token = ft_double_lstnew(temp);
	else
	{
		fill_data(split_temp,temp,data,check);
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
		init_data(data,input);
	}
    return (0);
}
