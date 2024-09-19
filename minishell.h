/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/19 21:37:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
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
	char	*cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_token	*token;
	t_cmd	*cmd;
}	t_data;

int		ft_strcmp(char *s1, char *s2);
int		check_type(t_token *temp);
int		is_not_arg_or_cmd(char *content);
int		init_token(t_data *data,char **line);
int		check_quote(char *input);
char	*ft_remove_front_and_back_space(char *str);
t_token	*ft_lstnew_cmd(char *content);
t_token	*ft_double_lstnew(char *content);
void	ft_lstadd_back(t_token **lst, t_token *new);
void	check_and_fill_token(char **line, t_data *data);
void	ft_is_arg_or_cmd(t_token *temp);
void	assigne_type_token(t_data *data);

#endif