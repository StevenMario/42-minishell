/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:39 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/31 10:55:25 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int check_dollar(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (str[i] == '$')
            return (1);
    }
    return (0);
}
int is_special_char(char c)
{
	if (c == '.' || c == '#'||c == '%'
            || c == '^' || c == '&' || c == '*'
            || c == '+' || c == '=' || c == '-'|| c == '}')
			return (1);
	return (0);
}
char *join_expand_char(char *val, char *pref, char *suf)
{
    char *str;

    str = NULL;
    if (pref)
		str = ft_strjoin(pref,val);
    else
        str = ft_strdup(val);
    if (suf)
        str = ft_strjoin(str,suf);
    printf("expand value = %s\n",str);
    return (str);
}