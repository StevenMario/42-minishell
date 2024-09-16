/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/09/16 18:16:56 by mrambelo         ###   ########.fr       */
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
	
}

int is_not_arg_or_cmd(char *content)
{
	if (ft_strcmp(content,"<") == 0)
		return (INPUT);
	else if (ft_strcmp(content,"<<") == 0)
		return (HEREDOC);
	else if (ft_strcmp(content,">") == 0)
		return  (TRUNC);
	else if (ft_strcmp(content,">>") == 0)
		return  (APPEND); 
	else if (ft_strcmp(content,"|") == 0)
		return  (PIPE);
	else
		return (-1);
}


int	is_cmd(t_token *temp)
{
	if (is_not_arg_or_cmd(temp->content) == -1)
	{
		if ((temp->next && is_not_arg_or_cmd(temp->next->content) == -1) ||
			(temp->prev && ft_strcmp(temp->prev->content, "|") == 0) ||
			!temp->prev)
			return CMD;
	}
	return (-1);
}

void	ft_is_arg_or_cmd(t_token *temp)
{
	if (is_not_arg_or_cmd(temp->content) == -1)
	{
		if (is_cmd(temp) == CMD)
			temp->type = CMD;
		else 
			temp->type = ARG;
	}
}

void assigne_type_token(t_data *data)
{
	t_token *temp;

	temp = data->token;
	while (temp)
	{
		if (is_not_arg_or_cmd(temp->content) == INPUT)
			temp->type = INPUT;
		else if (is_not_arg_or_cmd(temp->content) == HEREDOC)
			temp->type = HEREDOC;
		else if (is_not_arg_or_cmd(temp->content) == TRUNC)
			temp->type = TRUNC;
		else if (is_not_arg_or_cmd(temp->content) == APPEND)
			temp->type = APPEND; 
		else if (is_not_arg_or_cmd(temp->content) == PIPE)
			temp->type = PIPE;
		else
			ft_is_arg_or_cmd(temp);
		temp = temp->next;
	}
	while (data->token)
	{
		printf("data->token->content = %s  type == %d\n",data->token->content,data->token->type);
		data->token = data->token->next;
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