/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rfile_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:38:33 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/22 22:39:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmd.h"

void	ft_lstclear_file(t_file **lst)
{
	t_file	*temp;
	t_file	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			free(temp->content);
            free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}