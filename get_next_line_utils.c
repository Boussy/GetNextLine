/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:11:10 by bferdjan          #+#    #+#             */
/*   Updated: 2025/02/17 10:11:11 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (s + i);
	return (NULL);
}

static char	*allocate_and_init_s1(char *s1)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	lens12;
	size_t	lens1;
	char	*res;

	s1 = allocate_and_init_s1(s1);
	if (!s1)
		return (NULL);
	lens12 = ft_strlen(s1) + ft_strlen(s2);
	lens1 = ft_strlen(s1);
	res = malloc((lens12 + 1) * sizeof(char));
	if (!res || !s2)
		return (free(s1), free(res), NULL);
	i = 0;
	while (i != lens12)
	{
		if (i < lens1)
			res[i] = s1[i];
		else
			res[i] = s2[i - lens1];
		i++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res || !s2)
	{
		free(s1);
		return (NULL);
	}
	while (i != ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
			res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}*/
