/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:24 by mrambelo          #+#    #+#             */
/*   Updated: 2024/10/29 22:45:28 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void fill_data(t_data *data, char *temp)
{
	temp = ft_remove_front_and_back_space(temp);
	if (temp != NULL)
	{
		if (data->token == NULL)
					data->token = ft_double_lstnew_token(temp);
		else
				ft_lstadd_back_token(&data->token,ft_double_lstnew_token(temp));
 		free(temp);
	}
 }
char *fill_temp(char *input,int *i)
{
	char *temp;
	int		len;
	int		j;
	char	quote;
	int 	check;

	temp = NULL;
	len = 0;
	quote = 0;
	j = *i;
	while (input && input[*i] && (check_redire(input,*i) == -1))
	{
		quote = is_quote(input[*i]);
		if (quote)
		{
			len += ft_strchr(input + (*i) + 1, quote) - input + (*i);
			printf("str[len] = %c\n",input[len]);
			//  - input + (*i)
			*i += len;
		}
		else
		{
			(*i)++;
			len++;
		}
		// (*i)++;
		// len++;
		// printf("len = %d\n",len);
	}
	len--;
	check = check_redire(input,*i);
	if (check > -1)
		temp = fill_temp_with_redire(temp,check,i);
	else
		temp = ft_substr(input,j,len + 1);
	printf("temp = %s\n",temp);
	return NULL;





	// check = check_redire(input, i);
	// if (input[*i] == '\'' || input[*i] == '"')
	// {
	// 	*j = *i;
	// 	(*i)++;
	// 	temp = fill_temp_with_quote(i,j,&temp,input);
	// }
	// else if (check == PIPE || check == APPEND
	// 	|| check == INPUT || check == TRUNC || check == HEREDOC)
	// {
	// 	temp = fill_temp_with_redire(temp, check,i);
	// 	(*i)++;
	// }
	// else
	// {
	// 	*j = *i;
	// 	temp = fill_temp_without_quote(i,j,&temp,input);
	// }
	// return (temp);
}

void	init_token(t_data *data,char *input)
{
	// char *temp;
	int i;
	
	i = 0;
	(void)data;
	input = ft_strtrim(input, " ");
	while (input && input[i])
	{
		while (input[i] == ' ' && input[i])
			i++;
		fill_temp(input, &i);
		// if (temp && ft_is_space(temp))
		// {
		// 	free(temp);
		// 	break;
		// }
		// fill_data(data,temp);
		i++;
	}
	free(input);
}