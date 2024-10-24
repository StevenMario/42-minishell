/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:minishell.h
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/23 14:08:02 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "libft/libft.h"
=======
/*   Created: 2024/10/22 10:55:08 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 12:31:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_H
# define TOKEN_H
>>>>>>> main:init_token/token.h

#include "../src/minishell.h"
// # include "../src/structure.h"
// # include "../libft/libft.h"


<<<<<<< HEAD:minishell.h
typedef struct s_cmd
{
	char	**arg;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char	*key;
	char    *value;
	struct s_env	*prev;
	struct s_env    *next;
}		t_env;

typedef struct s_data
{
	t_token	*token;
	t_cmd	*cmd;
	t_env	*e_lst;
	t_env	*sorted_env;
}	t_data;

int		ft_strcmp(char *s1, char *s2);
int		check_redire(char *temp,int *i);
=======

>>>>>>> main:init_token/token.h
int		is_not_arg_or_cmd(char *content);
int		check_type(t_token *temp);
void	ft_is_arg_or_cmd(t_token *temp);
void	assigne_type_token(t_data *data);
char	*fill_temp(char *input,int *i,int *j);
void	fill_data(t_data *data, char *temp);
void	init_token(t_data *data,char *input);
int		check_redire(char *temp,int *i);
char	*fill_temp_with_quote(int *i,int *j,char **temp,char *input);
char	*fill_temp_without_quote(int *i,int *j,char **temp,char *input);
char	*fill_temp_with_redire(char *temp,int check,int *i);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
t_token	*ft_double_lstnew_token(char *content);
void	ft_print_token(t_token *token);

#endif
