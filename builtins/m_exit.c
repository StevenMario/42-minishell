/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:57:17 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/25 07:37:56 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	check_av_for_exit(char **arg, t_data *mish)
{
	if (arg[0] && !arg[1])
	{
		free_parser();
		exit (0);
	}
	if (count_av(arg) > 2)
	{
		free_parser();
		printf("minishell: exit: too many arguments\n");
		mish->exit_status = 1;
		return (1);
	}
	if (!ft_arg_is_digit(arg[1]))
	{
		free_parser();
		printf("exit: %s: numeric argument required\n", arg[1]);
		mish->exit_status = 255;
		exit(255);
	}
	return (0);
}

int	ft_arg_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int ft_exit(t_cmd *cmd, t_env	*env, t_data *mish)
{
	(void) env;
	free_lexer();
	free_env(mish->m_env);
	printf("exit\n");
	if (check_av_for_exit(cmd->arg, mish))
		return (1);
	mish->exit_status = ft_atoi_exit(cmd->arg[1]);
	free_parser();
	exit(mish->exit_status);
	return (0);
}