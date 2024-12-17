/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 17:10:21 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

void	print_token(t_token *token)
{
	while (token)
	{
		printf("token = %s\n", token->content);
		token = token->next;
	}
}

int	check_last_token(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp && temp->next)
		temp = temp->next;
	if (check_redir_type(temp->type) == 1)
	{
		ft_error_writer("syntax error near unexpected token",
			" :pipe or redir\n");
		return (1);
	}
	return (0);
}

void	init_data(t_data *data, char *input, char **env)
{
	int	backup[2];

	add_history(input);
	data->token = NULL;
	data->env = env;
	if (data && !data->e_lst)
		data->e_lst = fill_env_in_t_env(env);
	init_token(data, input);
	assigne_type_token(data);
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
