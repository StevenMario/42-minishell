/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:25:03 by mrambelo          #+#    #+#             */
/*   Updated: 2024/11/27 09:48:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	remove_quote_in_cmd_arg(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->arg)
	{
		while (cmd->arg[i])
		{
			if (check_quote(cmd->arg[i]))
				cmd->arg[i] = remove_quotes(cmd->arg[i]);
			i++;
		}
	}
}

void	remove_quote_in_cmd_rfile(t_file *rfile)
{
	while (rfile)
	{
		if (rfile->type != HEREDOC)
		{
			if (check_quote(rfile->content))
				rfile->content = remove_quotes(rfile->content);
		}
		rfile = rfile->next;
	}
}

void	cmd_processing(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	while (cmd)
	{
		remove_quote_in_cmd_arg(cmd);
		if (cmd->rfile)
			remove_quote_in_cmd_rfile(cmd->rfile);
		cmd = cmd->next;
	}
}
