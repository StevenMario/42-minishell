/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:14 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/01 14:00:53 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_H
#define CMD_H

#include "../src/minishell.h"
# include "../init_token/token.h"

int		get_nb_arg(t_token *token);
int     check_dollar(char *str);
int     cmd_processing(t_data *data);
int     init_file(t_token *token,t_cmd *cmd);
void	get_cmd(t_token *token, t_cmd *cmd);
void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new);
void	ft_add_back_infile(t_file **rfile, t_file *new_file);
void printf_infile(t_file *rfile);
void ft_print_cmd(t_cmd *cmd);
int     is_special_char(char c);
void	ft_lstclear_cmd(t_cmd **lst);
void	ft_lstclear_file(t_file **lst);
void fill_infile_expand(t_data *data);
void fill_outfile_expand(t_data *data);
t_cmd	*ft_initcmd(void);
char	*my_getenv(char *var_name, t_env *env);
void cmd_rfile_expand(t_file *rfile,t_env *e_list);
void	cmd_expand(t_data *data);
char    *join_expand_char(char *val, char *pref, char *suf);
#endif