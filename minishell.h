/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 14:01:11 by irabesan         ###   ########.fr       */
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

# define CMD 0
# define ARG 1
# define PIPE 2
# define INPUT 3
# define HEREDOC 4
# define TRUNC 5
# define APPEND 6
# define FILE 7
# define DELIMITER 8

typedef struct s_token
{
	char	*content;
	int		type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	char	**arg;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_lst
{
	char	*s;
	struct s_lst	*next;
	struct	s_lst	*prev;
}	t_lst;

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
}	t_data;

int		ft_sctrcmp(char *s1, char *s2);
int		check_redire(char *temp,int *i);
int		is_not_arg_or_cmd(char *content);
char	*fill_temp(char *input,int *i,int *j);
char	*ft_remove_front_and_back_space(char *str);
char	*fill_temp_with_redire(char *temp,int check,int *i);
char	*fill_temp_with_quote(int *i,int *j,char **temp,char *input);
char	*fill_temp_without_quote(int *i,int *j,char **temp,char *input);
void	ft_is_arg_or_cmd(t_token *temp);
void	 new_cmd(t_token *token,t_cmd **cmd);
void	assigne_type_token(t_data *data);
void	fill_data(t_data *data, char *temp);
void	init_token(t_data *data,char *input);
void	ft_lstadd_back(t_token **lst, t_token *new);
t_token	*ft_lstnew_cmd(char *content);
t_token	*ft_double_lstnew(char *content);

#endif
