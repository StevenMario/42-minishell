/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:06:15 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/20 15:42:57 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	print_exit_and_free(t_data *mish, int status)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	clear_data(mish);
	exit(status);
}

void	ft_do_error(char *strim, char *arg, t_data *mish)
{
	handling_exit_error(arg, ": numeric argument required\n", 1);
	clear_data(mish);
	free(strim);
	exit(2);
}

int	ft_do_error2(t_data *mish, char *arg)
{
	mish->exit_status = 1;
	return (handling_exit_error(arg, ":too many arguments\n", 2), 1);
}

char	*set_strim(char *str)
{
	char	*strim;

	strim = NULL;
	if (ft_count_char_in_str(str, ' ') == (int)ft_strlen(str))
		strim = ft_strdup(str);
	else
		strim = ft_strtrim(str, " \n\t");
	return (strim);
}
