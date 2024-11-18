/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:06 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/18 08:31:54 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "../src/minishell.h"
// # include "./structure.h"
int		ft_env_len(t_env *env);
int		exec_extern_cmd(t_env *env, t_cmd *cmd);
// int		ft_exec(t_cmd *cmd, t_env *env);
int	ft_exec_if_builtins(t_cmd *cmd, t_data	*mish, t_env *env);
int	exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env);
int	ft_is_builtin(t_cmd *cmd);


#endif