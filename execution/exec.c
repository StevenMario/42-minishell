/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/29 13:30:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(t_cmd *cmd, t_env *env)
{
	pid_t	pid;
	int	status;
	int	cmd_process;

	pid = fork();
	cmd_process = check_cmd_process(cmd);
	if (pid == 0 && cmd_process == 1)
		exit (0);
	if (pid == 0)
		exec_extern_cmd(env, cmd);
}