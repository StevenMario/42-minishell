/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:14 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 13:04:54 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_H
#define CMD_H

#include "../src/minishell.h"
# include "../init_token/token.h"

int		get_nb_arg(t_token *token);
void	get_cmd(t_token *token, t_cmd *cmd);
void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new);

#endif