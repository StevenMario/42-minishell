/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:32:04 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/13 11:14:06 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error_and_init_data(t_data **data, int argc)
{
	if (argc > 1)
	{
		ft_error_writer("[Error]", ":Run  minishell without argument !\n");
		return (1);
	}
	if (!*data)
		*data = data_initialized();
	return (0);
}

void	exit_ctrl_d(char *input, t_data *data)
{
	rl_clear_history();
	if (data)
		clear_data(data);
	if (input)
		free(input);
	exit(0);
}

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_status = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	init_signals(void)
{
	struct sigaction	action;

	memset(&action, 0, sizeof(action));
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT, SIG_IGN);
}
