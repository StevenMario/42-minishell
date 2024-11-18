/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:53 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/18 08:46:38 by irabesan         ###   ########.fr       */
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
int	ft_echo(char **echo);
int	ft_export(t_cmd *cmd, t_env *env);
void	ft_print_dx(t_env *env);
void	ft_lstadd_back_env(t_env **f_elem, t_env *n_elem);
t_env	*fill_env_in_t_env(char **envp);
t_env	*ft_double_lstnew_env(char *key, char *value);
t_env	*duplicate_env(t_env *src);
t_env	*init_t_env(void);

#endif