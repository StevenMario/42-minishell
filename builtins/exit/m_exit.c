/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:58:07 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/20 15:05:17 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

static int	ft_arg_is_nbr(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static long long	ft_atll(char *arg)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*arg && *arg == ' ')
		arg++;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign *= -1;
		arg++;
	}
	while (*arg >= '0' && *arg <= '9')
	{
		res = (res * 10) + (*arg - '0');
		arg++;
	}
	return ((res * sign) % 256);
}

static int	ft_arg_is_overlong(char *arg) // 1=isn't overlong, 0=is overlong
{
	char	*tmp;

	tmp = arg;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (ft_arg_is_nbr(arg) == 0 && ft_strlen(tmp) < 19)
		return (1);
	if (ft_strlen(tmp) > 19)
		return (0);
	if (ft_arg_is_nbr(arg) == 0 && ft_strcmp(arg, "9223372036854775807") > 0)
		return (0);
	if (ft_arg_is_nbr(arg) == 0 && arg[0] == '-'
		&& ft_strcmp(arg, "-9223372036854775808") > 0)
		return (0);
	return (1);
}

void	handling_exit_error(char *arg, char *m_err, int code_failure)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	if (code_failure == 1)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd(m_err, 2);
}

int	ft_exit(t_data *mish, t_cmd *cmd)
{
	long long	status;
	int			i;
	char		**str;
	char		*strim;

	status = mish->exit_status;
	strim = NULL;
	i = 1;
	if (cmd->arg[i] != NULL)
	{
		str = cmd->arg;
		// printf("str[i] = [%s]\n",str[i]);
		// printf("ft_is_space(str[i]) = %d\n",ft_is_space(str[i]));
		if (ft_count_char_in_str(str[i], ' ') == (int)ft_strlen(str[i]))
			strim = ft_strdup(str[i]);
		else
			strim = ft_strtrim(str[i], " \n\t");
		printf("strim = [%s]\n",strim);
		if (ft_arg_is_nbr(strim) == 1 || ft_arg_is_overlong(strim) == 0)
			ft_do_error(strim, str[i], mish);
		else if (count_av(str) > 2)
			return(ft_do_error2(mish, str[i]), 1);
		if (strim)
			free(strim);
		status = ft_atll(str[i]);
	}
	if (count_av((cmd->arg)) == 2 || count_av((cmd->arg)) == 1)
		print_exit_and_free(mish, status);
	return (status);
}
