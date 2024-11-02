/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:53 by irabesan          #+#    #+#             */
/*   Updated: 2024/11/02 21:56:42 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#define PATH_MAX 4096

# include "../src/minishell.h"
# include "../src/structure.h"

t_env	*fill_env_in_t_env(char **envp);
t_env   *init_t_env(void);
void    printf_t_env(t_env *env);
void    ft_echo(char **echo);

#endif