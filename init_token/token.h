/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:08 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/30 12:18:33 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_H
# define TOKEN_H

#include "../src/minishell.h"
// # include "../src/structure.h"
// # include "../libft/libft.h"



int		is_not_arg_or_cmd(char *content);
int		check_type(t_token *temp);
void	ft_is_arg_or_cmd(t_token *temp);
void	assigne_type_token(t_data *data);
char	*fill_temp(char *input,int *i);
void	fill_data(t_data *data, char *temp);
void	init_token(t_data *data,char *input);
int		check_redire(char *temp,int i);
char	*fill_temp_with_quote(int *i,int *j,char *input);
char	*fill_temp_without_quote(int *i,int *j,char *input);
char	*fill_temp_with_redire(char *temp,int check,int *i);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
t_token	*ft_double_lstnew_token(char *content);
void	ft_print_token(t_token *token);
void	ft_lstclear_token(t_token **lst);

#endif
