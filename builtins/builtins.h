/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:53 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/18 21:03:01 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define PATH_MAX 4096

# include "../src/minishell.h"
# include "../src/structure.h"

int		ft_cd(t_cmd *cmd, t_env *env);
int		update_env(char *var_name, char *new_val, t_env *env);
int		ft_unset(t_cmd *cmd, t_env *env);
int		ft_pwd(t_env *env);
int		ft_env(t_cmd *cmd, t_env *env);
void	printf_t_env(t_env *env);
int		ft_echo(char **echo);
int		ft_export(t_data *data);
int		ft_var_is_val(int c);
void	ft_print_dx(t_data *data);
void	ft_lstadd_back_env(t_env **f_elem, t_env *n_elem);
t_env	*fill_env_in_t_env(char **envp);
t_env	*ft_double_lstnew_env(char *key, char *value);
t_env	*duplicate_env(t_env *src);
void	ft_lstclear_env(t_env **lst);
t_env	*init_t_env(void);
int		count_av(char **av);
void	print_exit_and_free(t_data *mish, int status);
int		ft_exit(t_data *mish, t_cmd *cmd);
int		take_len_bf_char(char *str, char c);
void	ft_free_kval(char *k, char *val);
void	ft_swap(t_env *sort);
void	ft_do_error(char *strim, char *arg, t_data *mish);
void	handling_exit_error(char *arg, char *m_err, int code_failure);
int		ft_do_error2(t_data *mish, char *arg);

#endif