/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/19 21:25:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

int	check_last_token(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (!token)
		return (1);
	while (temp && temp->next)
		temp = temp->next;
	if (check_redir_type(temp->type) == 1 && temp->in_quote == 0)
	{
		ft_error_writer("syntax error near unexpected token",
			" :pipe or redir\n");
		return (1);
	}
	return (0);
}

void	process_token(t_token *token)
{
	t_token	*tmp;
	char	*str;

	tmp = token;
	str = NULL;
	while (tmp)
	{
		if ((ft_strcmp(tmp->content,"''") == 0
			&& (tmp->next && tmp->next->type == ARG)) 
			||(ft_strcmp(tmp->content,"\"\"") == 0
			&& (tmp->next && tmp->next->type == ARG)))
			str = ft_strdup(" ");
		else
			str = remove_quote_process(tmp->content);
		if (tmp->content)
			free(tmp->content);
		tmp->content = ft_strdup(str);
		if (str)
			free(str);
		tmp = tmp->next;
	}
}

void print_token(t_token *token)
{
	t_token *tmp;

	tmp = token;
	while (tmp)
	{
		printf("token = %s token->type = %d\n",tmp->content,tmp->type);
		tmp = tmp->next;
	}
}

void	init_data(t_data *data, char *input, char **env)
{
	int	backup[2];

	data->token = NULL;
	data->env = env;
	if (data && !data->e_lst)
		data->e_lst = fill_env_in_t_env(env);
	init_token(data, input);
	assigne_type_token(data);  
	// process_token(data->token);
	print_token(data->token);
	init_cmd(data);
	if (herdoc_handler(data) == 1)
	{
		ft_putendl_fd("", 1);
		clear_data_without_env(data);
		return ;
	}
	if (check_last_token(data->token) == 1)
	{
		clear_fd(data);
		clear_data_without_env(data);
		return ;
	}
	piping_cmd(data, backup);
}

t_data	*data_initialized(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->e_lst = NULL;
	data->cmd = NULL;
	data->env = NULL;
	data->token = NULL;
	data->exit_status = 0;
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_data	*data;

	(void)argv;
	input = NULL;
	data = NULL;
	if (check_error_and_init_data(&data, argc))
		return (1);
	while (1)
	{
		init_signals();
		data__token_cmd_initialized(data);
		input = readline("minishell$: ");
		add_history(input);
		if (input == NULL)
			exit_ctrl_d(input, data);
		if (input && *input != '\0' && !check_pair_quote(input))
			init_data(data, input, env);
		g_status = data->exit_status;
		clear_data_without_env(data);
	}
	rl_clear_history();
	return (0);
}
