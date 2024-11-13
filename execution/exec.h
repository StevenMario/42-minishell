/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:06 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/13 08:07:33 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "../src/minishell.h"
// # include "./structure.h"
int		ft_env_len(t_env *env);
int		exec_extern_cmd(t_env *env, t_cmd *cmd);
int		ft_exec(t_cmd *cmd, t_env *env);

#endif