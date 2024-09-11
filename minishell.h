/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/11 11:13:26 by mrambelo         ###   ########.fr       */
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

t_token	*ft_lstnew_cmd(char *content);
char *ft_remove_front_and_back_space(char *str);


#endif