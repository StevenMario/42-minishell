/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:06 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/05 07:57:31 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../src/minishell.h"

void	exec_redir_builtin(t_data *mish, t_cmd *cmd, t_env *env);
void	check_type_for_dup2(t_file *redir);
void	check_error_redir(t_file *redir);
void	ft_open_redir(t_file *redir);
void	ft_browse_redir(t_cmd *cmd);
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
void	piping_cmd(t_data *mish, int backup[2]);
void	clear_data_without_env(t_data *data);
char	**split_for_path(t_env *env);
char	*ft_join_env(char *s1, char *s2);
void	ft_free_env2d_pathspl(char **env_2d, char **path_spl, char *path);

#endif