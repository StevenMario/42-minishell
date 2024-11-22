/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:06 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/22 09:19:57 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "../src/minishell.h"
int		ft_count_cmd(t_data *mish);
void	dup_std(int r_fd[2]);
int		ft_env_len(t_env *env);
void	ft_restore_std(int backup[2]);
void	close_fds(int fd[2]);
int		exec_extern_cmd(t_env *env, t_cmd *cmd);
int		get_exit_status(int exit_status);
int		ft_exec_if_builtins(t_cmd *cmd, t_data	*mish, t_env *env);
int		exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env);
int		ft_is_builtin(t_cmd *cmd);


#endif