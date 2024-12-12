/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:23:50 by iarantsoa         #+#    #+#             */
/*   Updated: 2024/12/12 08:57:04 by irabesan         ###   ########.fr       */
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
			{
				printf("Minishell: export: '%s' not a valid identifier\n", arg);
				return (0);
			}
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

int	ft_pre_export(t_data *data, int l)
{
	t_var	v;

	if (check_valid_var(data->cmd->arg[l]) == 1)
	{
		if (ft_count_char_in_str(data->cmd->arg[l], '=') == 0)
			return (1);
		v.i = take_len_bf_char(data->cmd->arg[l], '=');
		if (v.i == 0)
		{
			printf("minishell: export: %s: not a valid identifier\n",
				data->cmd->arg[l]);
			return (1);
		}
		v.k = ft_substr(data->cmd->arg[l], 0, v.i);
		v.val = ft_strdup(data->cmd->arg[l] + (v.i + 1));
		if (!ft_if_var_exist(data->e_lst, v.k, v.val))
		{
			v.eenv = ft_double_lstnew_env(v.k, v.val);
			ft_lstadd_back_env(&data->e_lst, v.eenv);
			ft_lstclear_env(&v.eenv);
		}
		ft_free_kval(v.k, v.val);
	}
	return (0);
}

int	ft_export(t_data *data)
{
	int	l;

	l = 0;
	if (data->cmd->arg[1])
	{
		while (data->cmd->arg[++l])
		{
			if (check_valid_var(data->cmd->arg[l]) == 1)
			{
				if (ft_pre_export(data, l) == 1)
					return (1);
			}
		}
	}
	else
		ft_print_dx(data);
	return (0);
}
