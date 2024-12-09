/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand_rfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:23:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/04 10:55:57 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	cmd_rfile_expand(t_file *rfile, t_env *e_list)
{
	t_file	*temp;

	temp = rfile;
	while (temp)
	{
		if (temp && temp->content && check_dollar(temp->content) > -1)
			temp->content = check_var(temp->content, e_list);
		temp = temp->next;
	}
}

void	fill_rfile_expand(t_data *data)
{
	t_cmd	*cmd;
	t_file	*temp;

	cmd = data->cmd;
	while (cmd)
	{
		temp = cmd->rfile;
		while (temp && temp->type != HEREDOC)
		{
			cmd_rfile_expand(temp, data->e_lst);
			temp = temp->next;
		}
		cmd = cmd->next;
	}
}
