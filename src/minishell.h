/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/29 10:19:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "./structure.h"
# include "../init_token/token.h"
# include "../init_cmd/cmd.h"
# include "../builtins/builtins.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_print_token(t_token *token);
char	*ft_remove_front_and_back_space(char *str);
void	 new_cmd(t_token *token,t_cmd **cmd);
char    *remove_quotes(char *str);
int	check_quote(char *str);
char is_quote(char str);

#endif