/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:29:22 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/10/16 09:39:15 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_cmd *cmd, char **env)
{
    int i;

    i = 0;
    if (cmd->arg[1] == NULL)
    {
        while (env[i] != NULL)
        {
            if (ft_strschr(env[i], '=') != 0)
                printf("%s\n", env[i]);
            i++;
        }
        
    }
    else
    {
        printf("Too many arguments.\n");
        return (1);
    }
    return (0);
}