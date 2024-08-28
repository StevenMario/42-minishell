/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steven <steven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:35 by steven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*helper(char *stat, char *buff)
{
	char	*join;

	join = ft_strjoin_g(stat, buff);
	free(stat);
	return (join);
}

char	*fill_line_buffer(int fd, char *line_static)
{
	char	*buffer;

	if (!line_static)
	{
		line_static = (char *)malloc(sizeof(char) * 1);
		*line_static = '\0';
	}
	if (!line_static)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(line_static);
		return (NULL);
	}
	line_static = fill_line_static(line_static, fd, buffer);
	return (line_static);
}

char	*extract_line(char *line_static)
{
	int		i;
	int		len;
	char	*line;

	i = -1;
	len = 0;
	if (!line_static || !(*line_static))
		return (NULL);
	while (line_static[len] && line_static[len] != '\n')
		len++;
	if (line_static[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = line_static[i];
	line[i] = '\0';
	return (line);
}

char	*new_line_static(char *line_static)
{
	int		len;
	char	*new_line;

	len = 0;
	if (!line_static)
		return (NULL);
	if (!*line_static)
	{
		free(line_static);
		return (NULL);
	}
	while (line_static[len] != '\n' && line_static[len] != '\0')
		len++;
	if (line_static[len] == '\n')
		len++;
	new_line = check_and_fill_new_line(line_static, len);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_static;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_static = fill_line_buffer(fd, line_static);
	if (!line_static)
		return (NULL);
	line = extract_line(line_static);
	line_static = new_line_static(line_static);
	return (line);
}
