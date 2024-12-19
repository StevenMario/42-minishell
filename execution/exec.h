/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:06 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/19 15:49:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../src/minishell.h"
# include "../src/structure.h"

int		exec_redir_builtin(t_data *mish, t_cmd *cmd, t_env *env);
void	check_type_for_dup2(t_file *redir);
void	check_error_redir(t_file *redir);
void	ft_open_redir(t_file *redir);
void	ft_browse_redir2(t_cmd *cmd, t_data *data, int fds[2]);
int		ft_browse_builtins(t_cmd *cmd, t_data *data);
void	ft_browse_redir(t_cmd *cmd, t_data *data);
char	*get_path_for_exeve(char *cmd_arg, char *path, char **path_spl);
int		ft_count_cmd(t_data *mish);
void	dup_std(int r_fd[2]);
int		ft_env_len(t_env *env);
void	ft_restore_std(int backup[2]);
void	close_fds(int fd[2]);
int		exec_extern_cmd(t_env *env, t_cmd *cmd, t_data *mish);
int		get_exit_status(int exit_status);
int		ft_exec_if_builtins(t_cmd *cmd, t_data *mish, t_env *env);
int		exec_simple_cmd(t_data *mish, t_cmd *cmd, t_env *env, int backup[2]);
int		ft_is_builtin(t_cmd *cmd);
void	piping_cmd(t_data *mish, int backup[2]);
void	clear_data_without_env(t_data *data);
char	**split_for_path(t_env *env);
char	*ft_join_env(char *s1, char *s2);
void	ft_free_env2d_pathspl(char **env_2d, char **path_spl, char *path);
void	ft_error_writer(char *cmd, char *m_err);
void	handling_signal_parents(void);
void	handling_signal_child(void);
int		is_signal(t_cmd *cmd);
void	check_double_cmd(t_cmd *cmd);
void	clear_data_without_env(t_data *data);
void	set_pipe_cmd(t_data *mish, t_cmd *cmd, int backup[2]);
void	ft_exec_one_cmd(t_cmd *cmd, t_data *mish, int backup[2]);
void	ft_perror(char *m_err);
void	check_sg_for_nl(t_data *mish);
void	end_of_exec(t_data *mish, int backup[2]);
void	close_herdocc_fd(t_file *rfile);
void	ft_cmd_nt_found(t_cmd *cmd, char **env_2d, char **path_spl, char *path);
void	first_check_for_path(t_cmd *cmd, char *path, char **path_spl);
char	*ft_test_access(char **path_spl, char *cmd);
void	close_herdocc_fd(t_file *rfile);
void	clear_signals(t_data *mish);
void	ft_pre_execv(t_cmd *cmd, t_data *mish, int status, t_env *env);
void	ft_exit_w_st(t_data *mish, int status);
void	loop_exec_pcmd(int backup[2], t_data *mish);
char	*double_join_env(char *s1, char *s2);
char	*double_join_env1(char *s1, char *s2);
int		check_arg_point(t_exv exv, t_cmd *cmd);
char	*ft_path_n(t_env *env, char *cmd);
int		check_errno(char *path);

#endif