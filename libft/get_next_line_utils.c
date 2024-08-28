/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/07/18 11:55:01 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_g(const char *str, int searchChar)
{
	int		i;
	char	letter;

	i = 0;
	letter = (char)searchChar;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] == letter)
			return ((char *)str + i);
		i++;
	}
	if (((char *)str)[i] == '\0' && searchChar == '\0')
		return ((char *)str + i);
	return (0);
}

char	*fill_line_static(char *line_static, int fd, char *buffer)
{
	int		nbyte;

	nbyte = 1;
	while (nbyte)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(buffer);
			free(line_static);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		line_static = helper(line_static, buffer);
		if (ft_strchr_g(line_static, '\n'))
			break ;
	}
	free(buffer);
	return (line_static);
}

char	*check_and_fill_new_line(char *line_static, int len)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char)
			*(ft_strlen_g(line_static) - len + 1));
	if (!new_line)
	{
		free(line_static);
		return (NULL);
	}
	while (line_static[len + i] != '\0')
	{
		new_line[i] = line_static[len + i];
		i++;
	}
	new_line[i] = '\0';
	if (new_line[0] == '\0')
	{
		free(line_static);
		free(new_line);
		return (NULL);
	}
	free(line_static);
	return (new_line);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	s1_i;
	size_t	s2_i;

	i = 0;
	j = 0;
	s1_i = ft_strlen_g(s1);
	s2_i = ft_strlen_g(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * s1_i + s2_i + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
