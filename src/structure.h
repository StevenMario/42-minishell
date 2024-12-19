/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:20:56 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/19 09:27:31 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define CMD 0
# define ARG 1
# define PIPE 2
# define INPUT 3
# define HEREDOC 4
# define TRUNC 5
# define APPEND 6
# define FILES 7
# define DELIMITER 8

# include <unistd.h>
# include <sys/types.h>

typedef struct s_file
{
	char			*content;
	int				type;
	int				fd;
	struct s_file	*next;
}					t_file;

typedef struct s_cmd
{
	char			**arg;
	t_file			*rfile;
	pid_t			pid;
	int				status;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	char			**env;
	t_token			*token;
	t_cmd			*cmd;
	t_env			*e_lst;
	int				exit_status;
}					t_data;

typedef struct s_var
{
	int		i;
	char	*val;
	char	*k;
	t_env	*eenv;
}	t_var;

typedef struct s_pre_expd
{
	char	*res;
	char	*val_exp;
	char	**expd_val;
	int		in_s_quote;
	int		in_d_quote;
	char	*res_trim;
}	t_pre_expd;

typedef struct s_exv
{
	char	**env_2d;
	char	**path_spl;
	char	*path;/* data */
}	t_exv;

#endif
