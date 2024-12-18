/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_no_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:00:35 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/18 10:30:46 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**env_to_2d(t_env *env)
{
	char	**arr;
	int		j;

	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_env_len(env) + 1));
	while (env)
	{
		if (env->key && env->value)
			arr[j] = double_join_env(env->key, env->value);
		env = env->next;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	*ft_test_access(char **path_spl, char *cmd)
{
	char	*join_path;
	int		i;

	i = -1;
	while (path_spl[++i])
	{
		join_path = double_join_env1(path_spl[i], cmd);
		if (join_path && access(join_path, F_OK) == 0)
			return (join_path);
		if (join_path)
			free(join_path);
	}
	return (NULL);
}

int	check_error_execve(t_cmd *cmd, t_exv exv, t_data *mish)
{
	struct stat	sb;

	sb.st_mode = 0;
	lstat(exv.path, &sb);
	if (exv.path == NULL)
	{
		ft_cmd_nt_found(cmd, exv.env_2d, exv.path_spl, exv.path);
		return (mish->exit_status = 127);
	}
	else if (S_ISDIR(sb.st_mode))
	{
		ft_error_writer(exv.path, " :Is a directory\n");
		return (mish->exit_status = 126);
	}
	else if (access(exv.path, F_OK) == -1)
	{
		ft_error_writer(exv.path, " :no such file or directory\n");
		return (mish->exit_status = 127);
	}
	else if (access(exv.path, X_OK) == -1)
	{
		ft_error_writer(exv.path, " :permission denied\n");
		return (mish->exit_status = 127);
	}
	return (0);
}

t_exv	init_exv(void)
{
	t_exv	exv;

	exv.env_2d = NULL;
	exv.path_spl = NULL;
	exv.path = NULL;
	return (exv);
}

int check_arg_point(t_exv	exv, t_cmd *cmd)
{
	if (ft_strcmp(cmd->arg[0],".") == 0
	&& !cmd->arg[1])
	{
		ft_error_writer(cmd->arg[0], " :filename argument required\n");
		return (ft_free_env2d_pathspl(exv.env_2d, exv.path_spl, exv.path),2);
	}
	else if ((ft_strcmp(cmd->arg[0],".") == 0
	&& cmd->arg[1]))
	{
		ft_error_writer(cmd->arg[1], " :file not found\n");
		return (ft_free_env2d_pathspl(exv.env_2d, exv.path_spl, exv.path),1);
	}
	return (0);
}

int	exec_extern_cmd(t_env *env, t_cmd *cmd, t_data *mish)
{
	t_exv	exv;
	int		int_status;

	exv = init_exv();
	exv.env_2d = env_to_2d(env);
	exv.path_spl = split_for_path(env);
	if (cmd->arg && cmd->arg[0])
	{
		exv.path = get_path_for_exeve(cmd->arg[0], exv.path, exv.path_spl);
		int_status = check_arg_point(exv,cmd);
		if (int_status != 0)
			return (int_status);
		else
			int_status = check_error_execve(cmd, exv, mish);
		if (int_status != 0)
		{
			ft_free_env2d_pathspl(exv.env_2d, exv.path_spl, exv.path);
			return (int_status);
		}
		execve(exv.path, cmd->arg, exv.env_2d);
	}
	return (ft_free_env2d_pathspl(exv.env_2d, exv.path_spl, exv.path), 0);
}
