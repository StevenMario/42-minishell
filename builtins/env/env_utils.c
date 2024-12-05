/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:49:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/05 13:32:48 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	ft_lstadd_back_env(t_env **f_elem, t_env *n_elem)
{
	t_env	*temp;

	temp = *f_elem;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*f_elem = duplicate_env(n_elem);
	else
		temp->next = duplicate_env(n_elem);
}

char	**split_for_env(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	j = 0;
	k = 0;
	arr = (char **)malloc(3 * sizeof(char *));
	if (!arr)
	{
		printf("env_error\n");
		return (NULL);
	}
	while (str[i] && str[i] != '=')
		i++;
	arr[j++] = ft_substr(str, 0, i);
	k = i + 1;
	str = (str + k);
	arr[j] = ft_strdup(str);
	if (arr[1])
		arr[2] = NULL;
	else
		arr[1] = NULL;
	return (arr);
}

t_env	*fill_env_in_t_env(char **envp)
{
	int		i;
	t_env	*root;
	t_env	*temp;
	char	**split_env;

	i = -1;
	root = NULL;
	temp = NULL;
	while (envp[++i])
	{
		split_env = split_for_env(envp[i]);
		temp = ft_double_lstnew_env(split_env[0], split_env[1]);
		ft_lstadd_back_env(&root, temp);
		ft_lstclear_env(&temp);
		ft_free_str(split_env);
	}
	return (root);
}

t_env	*init_t_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

void	ft_lstclear_env(t_env **lst)
{
	t_env	*temp;
	t_env	*next;

	temp = (*lst);
	if (temp == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			next = (temp)->next;
			if (temp->value)
				free(temp->value);
			if (temp->key)
				free(temp->key);
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}
