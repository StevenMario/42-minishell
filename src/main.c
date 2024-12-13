/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 14:42:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

void	clear_data(t_data *data)
{
	if (data)
	{
		if (data->cmd)
			ft_lstclear_cmd(&data->cmd);	
		if (data->token)
			ft_lstclear_token(&data->token);
		if (data->e_lst)
			ft_lstclear_env(&data->e_lst);
		free(data);
	}
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
	herdoc_handler(data);
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

int	check_valid_input(char *input)
{
	char	*trim;
	int		len;

	trim = ft_strtrim(input, " \n\t");
	len = ft_strlen(trim);
	if ((trim && trim[0] && trim[1] && trim[len - 1]) 
			&& ((trim[len - 1] == '|' || trim[0] == '|') || (trim[len - 1] == '<'
			|| (trim[0] == '<' && trim[1] != '<')) || (trim[len - 1] == '>' || trim[0] == '>')))
	{
		if (trim)
			free(trim);
		ft_error_writer("syntax error near unexpected token",
			" :pipe or redir\n");
		return (1);
	}
	if (trim)
		free(trim);
	return (0);
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
		if (input && *input != '\0' && !check_valid_input(input)
			&& !check_pair_quote(input))
			init_data(data, input, env);
		g_status = data->exit_status;
		clear_data_without_env(data);
	}
	rl_clear_history();
	return (0);
}
