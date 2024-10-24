/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:49:38 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/24 06:56:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../builtins.h"

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
		printf("env_error\n");
		return (NULL);
	}
	while (str[i] && str[i] != '=')
		i++;
	arr[j++] = ft_substr(str, 0, i);
	k = i + 1;
	str = (str + k);
	arr[j] = ft_strdup(str);
	arr[3] = NULL;
	return (arr);
}

void	ft_lstadd_back_env(t_env **f_elem, t_env *n_elem)
{
	t_env	*temp;

	temp = *f_elem;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = n_elem;
			n_elem->prev = temp;
			n_elem->next = NULL;
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
	if (key)
		new_env->key = ft_strdup(key);
	if(value)
		new_env->value =  ft_strdup(value);
	new_env->next = NULL;
	return (new_env);
}

t_env	*fill_env_in_t_env(char **envp)
{
	int i;
	t_env *root;
	char **split_env;

	i = -1;
	root = NULL;
	while (envp[++i])
	{
		split_env = split_for_env(envp[i]);
		// printf("split_env[0] = %s   split_env[1] = %s\n",split_env[0],split_env[1]);
		ft_lstadd_back_env(&root, ft_double_lstnew_env(split_env[0], split_env[1]));
		ft_free_str(split_env);
	}
	return (root);
}

t_env *init_t_env(void)
{
	t_env *env;
	env = malloc(sizeof(t_env));
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
	env->prev = NULL;
	return (env);
}

void printf_t_env(t_env *env)
{
	while(env)
	{
		printf("[key = %s] == [value == %s]\n",env->key,env->value);
		env = env->next;
	}
}