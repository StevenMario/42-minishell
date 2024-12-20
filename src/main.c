/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/20 16:23:35 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

int	check_last_token(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (!token)
		return (0);
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

int	check_error_token(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (!token)
		return (0);
	if (token && token->type == PIPE)
		return (ft_error_writer("syntax error near unexpected token",
				" :pipe or redir\n"), 1);
	while (temp)
	{
		if (temp->next)
		{
			if ((check_redir_type2(temp->type))
				&& check_redir_type(temp->next->type))
				return (ft_error_writer("syntax error near unexpected token",
						" :pipe or redir\n"), 1);
		}
		temp = temp->next;
	}
	return (0);
}

void	init_data(t_data *data, char *input, char **env)
{
	int	backup[2];

	data->env = env;
	if (data && !data->e_lst)
		data->e_lst = fill_env_in_t_env(env);
	init_token(data, input);
	if (check_error_token(data->token))
	{
		ft_lstclear_token(&data->token);
		data->exit_status = 2;
		return ;
	}
	init_cmd(data);
	if (herdoc_handler(data) == 1)
	{
		ft_putendl_fd("", 1);
		return (clear_data_without_env(data));
	}
	if (check_last_token(data->token) == 1)
	{
		clear_fd(data);
		data->exit_status = 2;
		return (clear_data_without_env(data));
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
		data->token = NULL;
		if (input && *input != '\0' && !check_pair_quote(input))
			init_data(data, input, env);
		g_status = data->exit_status;
		clear_data_without_env(data);
	}
	rl_clear_history();
	return (0);
}
