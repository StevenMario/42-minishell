/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:29:22 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/10/24 11:46:47 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_cmd *cmd, t_env *env)
{
    t_env *tmp;

    if (cmd->arg[1] == NULL)
    {
        tmp = env;
        while (tmp)
        {
            printf("%s", tmp->key);
            printf("=");
            printf("%s\n", tmp->value);
        }
        
    }
    else
    {
        printf("Too many arguments.\n");
        return (1);
    }
    return (0);
}