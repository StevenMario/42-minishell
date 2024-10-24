/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:04:31 by irabesan          #+#    #+#             */
/*   Updated: 2024/10/24 06:53:56 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"
char	**split_for_env(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**arr;

	i = 0;
	j = 0;
	k = 0;
	arr = (char **)malloc(3 * sizeof(char *));
	if (!arr)
	{
		print_error(1);
		return (NULL);
	}
	while (str[i] && str[i] != '=')
		i++;
	arr[j++] = ft_substr(str, 0, i);
	k = i + 1;
	str += (str + k);
	arr[j] = ft_strdup(str);
	arr[3] = NULL;
	return (arr);
}
t_env	*stock_third_param(char **envp)
{
	int i;
	t_env *root;
	char **split_env;

	i = -1;
	while (envp[++i])
	{
		split_env = split_for_env(envp[i]);
		ft_lstadd_back_env(&root, ft_double_lstnew_env(split_env[0], split_env[1]));
		ft_free_str(split_env);
	}
	return (root);
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
	if (!temp)
		temp = n_elem;
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