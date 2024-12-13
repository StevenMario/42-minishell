/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:08 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/13 09:46:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../src/minishell.h"
# include "../src/structure.h"

int			is_not_arg_or_cmd(char *content);
int			check_type(t_token *temp);
int			check_redire(char *temp, int i);
char		*fill_temp(char *input, int *i);
char		*fill_temp_with_quote(int *i, int *j, char *input);
char		*fill_temp_without_quote(int *i, int *j, char *input);
char		*fill_temp_with_redire(char *temp, int check, int *i, char *input);
void		ft_is_arg_or_cmd(t_token *temp);
void		fill_data(t_data *data, char *temp);
void		init_token(t_data *data, char *input);
void		assigne_type_token(t_data *data);
void		ft_lstadd_back_token(t_token **lst, t_token *new);
void		ft_lstclear_token(t_token **lst);
t_token		*ft_double_lstnew_token(char *content);
char		*check_exit_status(char *check_status);
char		*char_append(char *str, char c);
char		*get_val(char *str, int *i, t_env *e_list);
char		*remove_quote_process(char *str);
int			chech_in_quote(char c, int *in_d_quote, int *in_s_quote);
char		**check_var(char *str, t_env *e_list);
int			sould_expand(int i, char *str, int in_s_quote);
char		*char_append(char *str, char c);
int			is_ingored_dollars(char *str, int i, int in_d_quote,
				int in_s_quote);
char		*fill_res(char *res, int in_d_quote, int in_s_quote, char c, int i,
				char *str);
int			get_len_str(char **str);
char		**str_append(char **str, char *new_str);
t_pre_expd	init_t_expand(void);
int	check_redir_type(int check);

#endif
