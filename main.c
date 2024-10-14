/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/14 10:34:32 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_and_fill_redire(t_data *data, int check,char **split_temp,int *i)
{
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
	
	if (split_temp != NULL && *split_temp)
	{
		i = -1;
		while (split_temp[++i])
		{
			if (data->token == NULL)
			{
				data->token = ft_double_lstnew(split_temp[i]);
				add_content(data, check,split_temp, &i);
				i++;
			}
			if_split_temp_exist(split_temp,data,check,&i);
		}
	}
	else
	{
		if (data->token == NULL)
				data->token = ft_double_lstnew(temp);
		else
			ft_lstadd_back(&data->token,ft_double_lstnew(temp));
	}
				
}

void if_split_temp_exist(char **split_temp, t_data *data, int check, int *i)
{
	char **resplit;
	int check_resplit;
 
	resplit = NULL;
	check_resplit = check_redire(split_temp[*i]);
	if (check_resplit > -1)
	{
		
		resplit = fill_split_temp(split_temp[*i] ,check_resplit);
		if (!split_temp[*i + 1] || check == PIPE)
			add_content(data, check,split_temp, i);
		fill_data(resplit,split_temp[*i],data,check_resplit);
		ft_free_str(resplit);
	}
	else
	{
		if (!split_temp[*i + 1])
		{
			add_content(data, check,split_temp, i);
		}	
		ft_lstadd_back(&data->token,ft_double_lstnew(split_temp[*i]));
		check_and_fill_redire(data,check,split_temp, i);
	}
	while (data->token)
	{
		printf("data->token->content = %s \n",data->token->content);
		data->token = data->token->next;
	}
	
}



void fill_token(t_data *data, char *temp)
{
	int check;
	char **split_temp;
	
	split_temp = NULL;
	check = check_redire(temp);
	if (check > -1)
		split_temp = fill_split_temp(temp ,check);
	fill_data(split_temp,temp,data,check);
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
	data->token = NULL;
	init_token_with_quote(data,input);
	assigne_type_token(data);
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
		init_data(data,input);
	}
    return (0);
}
