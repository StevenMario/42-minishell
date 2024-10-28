/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:33:52 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/25 06:56:53 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "./structure.h"
# include "../init_token/token.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_print_token(t_token *token);
int		check_redire(char *temp,int *i);
char	*ft_remove_front_and_back_space(char *str);
void	 new_cmd(t_token *token,t_cmd **cmd);
// t_token	*ft_lstnew_cmd(char *content);

#endif