/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:08 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/10 12:36:13 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../src/minishell.h"
# include "../src/structure.h"

int		is_not_arg_or_cmd(char *content);
int		check_type(t_token *temp);
int		check_redire(char *temp, int i);
char	*fill_temp(char *input, int *i);
char	*fill_temp_with_quote(int *i, int *j, char *input);
char	*fill_temp_without_quote(int *i, int *j, char *input);
char	*fill_temp_with_redire(char *temp, int check, int *i);
void	ft_is_arg_or_cmd(t_token *temp);
void	fill_data(t_data *data, char *temp);
void	init_token(t_data *data, char *input);
void	assigne_type_token(t_data *data);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
void	ft_lstclear_token(t_token **lst);
t_token	*ft_double_lstnew_token(char *content);
t_token *ft_strdup_token(t_token *token);
char	**check_var(char *str, t_env *e_list);

#endif
