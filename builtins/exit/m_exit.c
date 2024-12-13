/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:58:07 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/12 11:39:43 by irabesan         ###   ########.fr       */
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
	return (res * sign);
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
	if (ft_arg_is_nbr(arg) == 0 && ft_strcmp(arg, "-9223372036854775808") > 0)
		return (0);
	return (1);
}

static void	handling_exit_error(char *arg, char *m_err, int code_failure)
{
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

	status = mish->exit_status;
	i = 1;
	if (cmd->arg[i] != NULL)
	{
		str = cmd->arg;
		if (ft_arg_is_nbr(str[i]) == 1 || ft_arg_is_overlong(str[i]) == 0)
		{
			handling_exit_error(str[i], ": numeric argument required\n", 1);
			clear_data(mish);
			exit(2);
		}
		else if (count_av(str) > 2)
		{
			mish->exit_status = 1;
			return (handling_exit_error(str[i], ":too many arguments\n", 2), 2);
		}
		status = ft_atll(str[i]);
	}
	if (count_av((cmd->arg)) == 2 || count_av((cmd->arg)) == 1)
		print_exit_and_free(mish, status);
	return (status);
}
