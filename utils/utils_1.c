/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:04:31 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/21 12:22:11 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

t_env	*stock_third_param(char **envp)
{

}
void	ft_lstadd_back_env(t_env **f_elem, t_env *n_elem)
{
	t_env	*temp;

	temp = *f_elem;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next == n_elem;
			n_elem->prev == temp;
			n_elem->next == NULL;
			break;
		}
		temp = temp->next;
	}
}

t_env	*ft_double_lstnew_env(char *key, char *value)
{
	t_env		*new_env;

	new_env = malloc(sizeof(t_env));
	if (!new_env)
		return (NULL);
	new_env->prev = NULL;
	new_env->key = ft_strdup(key);
	new_env->value =  ft_strdup(value);
	new_env->next = NULL;
	return (new_env);
}

void	free_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	return ;
}