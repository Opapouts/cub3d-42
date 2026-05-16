/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:53:52 by dminh             #+#    #+#             */
/*   Updated: 2026/02/03 14:40:02 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buffer, int fd, char *line, size_t *len)
{
	ssize_t	reading;

	reading = 1;
	while (!ft_is_nl(line) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
		{
			if (line)
				free(line);
			buffer[0] = '\0';
			return (NULL);
		}
		if (reading == 0)
			break ;
		buffer[reading] = '\0';
		line = ft_set_line(line, buffer, len);
		if (!line)
		{
			buffer[0] = '\0';
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	size_t		len;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	len = 0;
	if (buffer[0])
	{
		line = ft_set_line(line, buffer, &len);
		if (!line)
		{
			buffer[0] = '\0';
			return (NULL);
		}
	}
	line = ft_read_line(buffer, fd, line, &len);
	if (!line)
		return (NULL);
	ft_del_printed(buffer);
	return (line);
}
