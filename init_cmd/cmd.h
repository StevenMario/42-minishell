/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:14 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/09 20:47:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "../src/minishell.h"
# include "../init_token/token.h"

int		get_nb_arg(t_token *token);
int		check_dollar(char *str);
int		init_file(t_token *token, t_cmd *cmd);
t_file	*ft_init_file(void);
int		is_special_char(char c);
char	*my_getenv(char *var_name, t_env *env);
char	*join_expand_char(char *val, char *pref, char *suf);
void	cmd_processing(t_data *data);
void	get_cmd(t_token *token, t_cmd *cmd);
void	ft_add_back_rfile(t_file **rfile, t_file *new_file);
void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new);
void	ft_lstclear_cmd(t_cmd **lst);
void	ft_lstclear_file(t_file **lst);
t_cmd	*duplicate_cmd(t_cmd *cmd);
void	fill_rfile_expand(t_data *data);
void	cmd_rfile_expand(t_file *rfile, t_env *e_list);
t_file	*duplicate_file(t_file *file);
void	cmd_expand(t_data *data);
char	*get_var_sufix(char *str, int var_len);
char	*get_var_prefix(char *str,int start);
char	*my_getenv2(char *var_name, t_env *env);
char	*check_var(char *str, t_env *e_list);
t_cmd	*ft_initcmd(void);
void	printf_rfile(t_file *rfile);
void	herdoc_handler(t_data *data);
t_cmd	*ft_initcmd(void);

#endif