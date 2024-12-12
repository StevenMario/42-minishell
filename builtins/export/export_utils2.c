/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:50:56 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/12 08:57:17 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	ft_free_kval(char *k, char *val)
{
	free(k);
	free(val);
}

void	ft_swap(t_env *sort)
{
	char	*tmp_k;
	char	*tmp_v;

	tmp_k = NULL;
	tmp_v = NULL;
	tmp_k = sort->next->key;
	tmp_v = sort->next->value;
	sort->next->key = sort->key;
	sort->next->value = sort->value;
	sort->key = tmp_k;
	sort->value = tmp_v;
}
