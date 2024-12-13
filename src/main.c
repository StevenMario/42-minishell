/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 08:47:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_status;

void init_cmd(t_data *data)
{
	data->cmd = NULL;
	new_cmd(data->token,&data->cmd);
}

void clear_data(t_data *data)
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

int init_data(t_data *data, char *input,char **env)
{
	int	backup[2];
	
	data->token = NULL;
	data->env = env;
	if (data && !data->e_lst)
		data->e_lst = fill_env_in_t_env(env);
	init_token(data,input);
	assigne_type_token(data);
	init_cmd(data);
	herdoc_handler(data);
	piping_cmd(data, backup);
	
	return 1;
}
int check_pair_quote(char *input)
{
	int check_dquote;
	int check_squote;

	check_dquote = ft_count_char_in_str(input,'"') % 2;
	check_squote = ft_count_char_in_str(input,'\'') % 2;
	if (check_dquote != 0 || check_squote != 0)
	{
		printf("minishell: unclosed quote detected\n");
		return (1);
	}
	return (0);
}

void exit_ctrl_d(char *input,t_data *data)
{
	rl_clear_history();
	if (data)
		clear_data(data);
	if (input)
		free(input);
	exit(0);
}

void signal_handler(int signal)
{
   if (signal == SIGINT)
   {
		g_status = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("",1);
		rl_redisplay();
   }
}
void init_signals(void)
{
	struct sigaction action;

	memset(&action, 0, sizeof(action));
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT,SIG_IGN);
}

t_data *data_initialized(void)
{
	t_data *data;

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
void data__token_cmd_initialized(t_data *data)
{
	data->cmd = NULL;
	data->env = NULL;
	data->token = NULL;
}

int check_valid_input(char *input)
{
	char *trim;
	int len;

	trim = ft_strtrim(input," \n\t");
	len = ft_strlen(trim);
	if ((trim[len -1] == '|' || trim[0] == '|' )
	|| (trim[len -1] == '<' || trim[0] == '<' )
	|| (trim[len -1] == '>' || trim[0] == '>' ))
	{
		if (trim)
			free(trim);
		ft_error_writer("syntax error near unexpected token", " :pipe or redir\n");
		return (1);
	}
	if (trim)
		free(trim);
	return (0);
}

int main(int argc,char **argv,char **env)
{
	char *input;
	t_data *data;

	(void)argv;
	input = NULL;
	data = NULL;
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	if (!data)
		data = data_initialized();
	while (1)
	{
		init_signals();
		data__token_cmd_initialized(data);
		input = readline("minishell$: ");
		if (input == NULL)
			exit_ctrl_d(input,data);
		if (input && *input != '\0' && !check_valid_input(input)
			&& !check_pair_quote(input))
			{
				add_history(input);
				if (!init_data(data,input,env))
					return (1);
			}
		g_status = data->exit_status;
		clear_data_without_env(data);
	}
	rl_clear_history();
    return (0);
}
