/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/28 13:12:27 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_status;

void init_cmd(t_data *data)
{
	data->cmd = NULL;
	new_cmd(data->token,&data->cmd);
	cmd_expand(data);
	if (data && data->cmd && data->cmd->rfile)
		fill_rfile_expand(data);
	// if (data && data->cmd && data->cmd->outfile)
	// 	fill_outfile_expand(data);
	cmd_processing(data);
}

void clear_data(t_data *data)
{
	if (data)
	{
		if (data->cmd)
			ft_lstclear_cmd(&data->cmd);
		if (data->token)
			ft_lstclear_token(&data->token);
		free(data);
	}
}
// void print_token(t_token *token)
// {
// 	while (token)
// 	{
// 		printf("token->type  = %d || token content = %s\n",token->type,token->content);
// 		token = token->next;
// 	}
// }



int init_data(t_data *data, char *input,char **env)
{
	int	backup[2];
	// data->token = malloc(sizeof(t_token));
	// if (!data->token)
	// 	return (0);
	data->token = NULL;
	data->env = env;
	if (data && !data->e_lst)
		data->e_lst = fill_env_in_t_env(env);
	init_token(data,input);
	assigne_type_token(data);
	init_cmd(data);
	herdoc_handler(data);
	piping_cmd(data, backup);
	// print_token(data->token);
	//exec_simple_cmd(data, data->cmd, data->e_lst);
	// ft_print_cmd(data->cmd);
	// clear_data(data);
	// ft_print_token(data->token);
	// printf_t_env(data->e_lst);
	// <file1 echo>>app test"test" >out.txt<<doc|cat -e "test'hello'" <<heredoc
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
	if (data)
		clear_data(data);
	rl_clear_history();
	if (input)
		free(input);
	exit(0);
}

void signal_handler(int signal)
{
   if (signal == SIGINT)
   {
		get_status = 130;
		printf("\n");
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
	return (data);
}

int main(int argc,char **argv,char **env)
{
	char *input;
	t_data *data;

	(void)argv;
	// data = malloc(sizeof(t_data));
	data  = data_initialized();
	// if (!data || !data->e_lst)
	// 	return (NULL);
	input = NULL;
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	init_signals();
	while (1)
	{
		input = readline("minishell$: ");
		if (input == NULL)
			exit_ctrl_d(input,data);
		if (input && *input != '\0' && !ft_is_space(input)
			&& !check_pair_quote(input))
			{
				add_history(input);
				if (!init_data(data,input,env))
					return (1);
			}
	}
    return (0);
}
