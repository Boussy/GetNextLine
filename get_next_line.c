/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:57:22 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/09 02:51:40 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

static int	has_leftover_or_eof(char *leftover, int bytes_read)
{
	if (bytes_read == 0 && (!leftover || *leftover == '\0'))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			leftover = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		//printf("Buffer: '%s'\n", buffer);
		if (!leftover)
			leftover = ft_strdup("");
		//printf("Leftover before strjoin: '%s'\n", leftover);
		leftover = ft_strjoin(leftover, buffer);
		if (!leftover)
			return (NULL);
		//printf("Leftover after strjoin: '%s'\n", leftover);
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	if (!has_leftover_or_eof(leftover, bytes_read))
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = extract_line(&leftover);
	//printf("Extracted line: '%s'\n", line);
	return (line);
}


/*char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		leftover = ft_strjoin(leftover, buffer);
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	line = extract_line(&leftover);
	return (line);
}*/
