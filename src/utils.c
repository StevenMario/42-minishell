/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:45 by mrambelo          #+#    #+#             */
/*   Updated: 2024/12/18 20:37:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (c);
	return (0);
}

int	check_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
	}
	return (0);
}

void	data__token_cmd_initialized(t_data *data)
{
	data->cmd = NULL;
	data->env = NULL;
	data->token = NULL;
}

int	check_pair_quote(char *input)
{
	int	check_dquote;
	int	check_squote;

	check_dquote = ft_count_char_in_str(input, '"') % 2;
	check_squote = ft_count_char_in_str(input, '\'') % 2;
	if (check_dquote != 0 || check_squote != 0)
	{
		printf("minishell: unclosed quote detected\n");
		free(input);
		return (1);
	}
	return (0);
}
