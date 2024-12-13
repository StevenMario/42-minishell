/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:48:29 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/12 10:19:15 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_exec_one_cmd(t_cmd *cmd, t_data *mish)
{
	check_double_cmd(cmd);
	exec_simple_cmd(mish, cmd, mish->e_lst);
	if (mish->exit_status == 130 || mish->exit_status == 131)
		write(1, "\n", 2);
}

void	ft_exec_mltpl_cmd(t_cmd *cmd, t_data *mish, int backup[2])
{
	check_double_cmd(cmd);
	set_pipe_cmd(mish, cmd, backup);
}

void	check_sg_for_nl(t_data *mish)
{
	if (mish->exit_status == 130 || mish->exit_status == 131)
		write(1, "\n", 1);
	else if (is_signal(mish->cmd) != 0)
		write(1, "\n", 1);
}

void	end_of_exec(t_data *mish, int backup[2])
{
	check_sg_for_nl(mish);
	ft_restore_std(backup);
	close_fds(backup);
	clear_data_without_env(mish);
}