/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:38:39 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/17 16:40:04 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*double_join_env(char *s1, char *s2)
{
	char	*r1;

	if (!s1)
		return (NULL);
	r1 = ft_join_env(s1, "=");
	if (!r1)
		return (NULL);
	r1 = ft_strjoin(r1, s2);
	if (!r1)
		return (NULL);
	return (r1);
}

char	*double_join_env1(char *s1, char *s2)
{
	char	*r1;

	if (!s1)
		return (NULL);
	r1 = ft_join_env(s1, "/");
	if (!r1)
		return (NULL);
	r1 = ft_strjoin(r1, s2);
	if (!r1)
		return (NULL);
	return (r1);
}
