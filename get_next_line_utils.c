/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:57:49 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/09 03:02:43 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = s1 ? ft_strlen(s1) : 0;
	len2 = s2 ? ft_strlen(s2) : 0;
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	if (s1)
		ft_memcpy(new_str, s1, len1);
	if (s2)
		ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = ft_strlen(src);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*extract_line(char **rest)
{
	char	*line;
	char	*newline_pos;
	char	*new_rest;
	size_t	line_len;

	if (!rest || !*rest)
		return (NULL);
	newline_pos = ft_strchr(*rest, '\n');
	if (newline_pos)
		line_len = newline_pos - *rest + 1;
	else
		line_len = ft_strlen(*rest);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *rest, line_len);
	line[line_len] = '\0';
	if (newline_pos)
		new_rest = ft_strdup(*rest + line_len);
	else
		new_rest = NULL;
	free(*rest);
	*rest = new_rest;
	return (line);
}