/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:14 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/19 19:49:03 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "../init_token/token.h"
# include "../src/minishell.h"

int		get_nb_arg(t_token *token);
int		check_dollar(char *str);
int		init_file(t_token *token, t_cmd *cmd);
t_file	*ft_init_file(void);
int		is_special_char(char c);
char	*my_getenv(char *var_name, t_env *env);
void	get_cmd(t_token *token, t_cmd *cmd);
void	ft_add_back_rfile(t_file **rfile, t_file *new_file);
void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new);
void	ft_lstclear_cmd(t_cmd **lst);
void	ft_lstclear_file(t_file **lst);
t_file	*duplicate_file(t_file *file);
char	*my_getenv2(char *var_name, t_env *env);
t_cmd	*ft_initcmd(void);
int		herdoc_handler(t_data *data);
t_cmd	*ft_initcmd(void);
void	init_cmd(t_data *data);
void	ft_free_and_close_fd(char *input, int fd);
void	clear_fd(t_data *data);
void	exit_status(t_data *data);
void	sig_heredoc(int signum);
void	ft_clear_sigint(t_data *data, int fd);
void	fill_herdocc_fd(t_file *rfile, t_data *data, int fd[2]);
void	ft_pre_herdoc(t_data *data, t_file *rfile, int fd[2]);
void check_null_content(t_token **token);
#endif