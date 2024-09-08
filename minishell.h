/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/09/08 18:48:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

# define CMD 0
# define ARG 1
# define PIPE 2
# define INPUT 3
# define HEREDOC 4
# define TRUNC 5
# define APPEND 6

typedef struct s_token
{
	char    *content;
	int     type;
	struct s_token *prev;
	struct s_token *next;
}   t_token;

typedef struct s_data
{
	t_token *token;
}   t_data;

#endif