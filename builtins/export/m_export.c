/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:23:50 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/04 10:09:31 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

static int	ft_var_is_val(int c)
{
	if (ft_isdigit(c) == 1)
		return (1);
	else if (ft_isalpha(c) == 1)
		return (1);
	else if (c == '_')
		return (1);
	else
		return (0);
}

static int	check_valid_var(char *arg)
{
	int	i;

	if (arg[0] && (ft_isdigit(arg[0]) == 1))
	{
		printf("Minishell: export: '%s' not a valid identifier\n", arg);
		return (0);
	}
	else
	{
		i = 0;
		while (arg[i] && arg[i] != '=')
		{
			if (ft_var_is_val(arg[i]) == 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_if_var_exist(t_env *env, char *k, char *val)
{
	while (env)
	{
		if (ft_strcmp(env->key, k) == 0)
		{
			free(env->value);
			env->value = ft_strdup(val);
			return (1);
		}
		else
			env = env->next;
	}
	return (0);
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	int		i;
	int		l;
	char	*val;
	char	*k;

	l = 0;
	if (cmd->arg[1])
	{
		while (cmd->arg[++l])
		{
			if (check_valid_var(cmd->arg[l]) == 1)
			{
				if (ft_count_char_in_str(cmd->arg[l], '=') == 0)
					return (1);
				i = take_len_bf_char(cmd->arg[l], '=');
				k = ft_substr(cmd->arg[l], 0, i);
				val = ft_strdup(cmd->arg[l] + (i + 1));
				if (!ft_if_var_exist(env, k, val))
					ft_lstadd_back_env(&env, ft_double_lstnew_env(k, val));
			}
		}
	}
	else
		ft_print_dx(env);
	return (0);
}
