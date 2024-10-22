/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:20:56 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 15:02:48 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
#define STRUCTURE_H

# define CMD 0
# define ARG 1
# define PIPE 2
# define INPUT 3
# define HEREDOC 4
# define TRUNC 5
# define APPEND 6
# define FILES 7
# define DELIMITER 8

typedef struct s_file
{
	char *content;
	int type;
	struct s_file *next;
}	t_file;

typedef struct s_cmd
{
	char	**arg;
	t_file	*infile;
	t_file	*outfile;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_token
{
	char	*content;
	int		type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	t_token	*token;
	t_cmd	*cmd;
}	t_data;

#endif