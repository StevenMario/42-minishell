/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:14 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 22:25:14 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_H
#define CMD_H

#include "../src/minishell.h"
# include "../init_token/token.h"

int		get_nb_arg(t_token *token);
void	get_cmd(t_token *token, t_cmd *cmd);
void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new);
void	ft_add_back_infile(t_file **rfile, t_file *new_file);
int     init_file(t_token *token,t_cmd *cmd);
void printf_infile(t_file *rfile);
void ft_print_cmd(t_cmd *cmd);
t_cmd	*ft_initcmd(void);

#endif