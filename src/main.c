/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:07:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/27 22:28:50 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *fill_res(int len,int i,int j,char *str)
{
	char *res;

	res = (char *)malloc(sizeof(char) *len + 1);
	if (!res)
		return (NULL);
	res = ft_substr(str,j,i);
	return (res);
}

void	check_var(char *str,t_env *e_list)
{
	int i;
	int	j;
	char *res;
	char *val;
	int var_len;
	i = -1;
	var_len = 0;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			i++;
			j = i;
			while (str[i] && (str[i] != ' ' && str[i] != '.'
				&& str[i] != '$'))
			{
				var_len++;
				i++;
			}
			i--;
			// printf("i = %d  j = %d\n",i,j);
			res = fill_res(var_len,i,j,str);
			printf("res = %s\n",res);
			val = my_getenv(res, e_list);
			printf("val = %s\n",val);
		}
	}
}

void change_var_in_env_var(t_data *data)
{
	int i;
	t_cmd *cmd;

	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->arg[i])
		{
			check_var(cmd->arg[i],data->e_lst);
			i++;
		}
		cmd = cmd->next;	
	}
}

void init_cmd(t_data *data)
{
	data->cmd = NULL;
	new_cmd(data->token,&data->cmd);
	change_var_in_env_var(data);
	cmd_processing(data);
}
void clear_data(t_data *data)
{
	ft_lstclear_cmd(&data->cmd);
	ft_lstclear_token(&data->token);
	free(data);
}
int init_data(t_data *data, char *input,char **env)
{	
	data->token = malloc(sizeof(t_token));
	if (!data->token)
		return (0);
	data->token = NULL;
	data->env = env;
	data->e_lst = fill_env_in_t_env(env);
	init_token(data,input);
	assigne_type_token(data);
	init_cmd(data);
	// ft_print_cmd(datla->cmd);
	// printf_t_env(data->e_lst);
	// clear_data(data);
	// <file1 echo>>app test"test" >out.txt<<doc|cat -e "test'hello'" <<heredoc
	return 1;
}

int main(int argc,char **argv,char **env)
{
	char *input;
	t_data *data;

	(void)argv;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (argc > 1)
		printf("[Error].Run without argument !\n");
	while (1)
	{
		input = readline("minishell$: ");
		if (input)
		{
			 add_history(input);
			if (!init_data(data,input,env))
				return (1);
		}
	}
    return (0);
}
