/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/27 10:27:10 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../libft/libft.h"
# include "./structure.h"
# include "../init_token/token.h"
# include "../init_cmd/cmd.h"
# include "../execution/exec.h"
# include "../builtins/builtins.h"
# include <sys/types.h>
# include <sys/wait.h>

int		ft_strcmp(char *s1, char *s2);
void	 new_cmd(t_token *token,t_cmd **cmd);
char    *remove_quotes(char *str);
int     check_quote(char *str);
char	is_quote(char c);
void clear_data(t_data *data);

#endif