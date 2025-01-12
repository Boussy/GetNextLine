/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:57:30 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/09 03:03:27 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32 // Tu peux définir cette valeur par défaut ou la personnaliser à la compilation

#endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

// Fonctions utilitaires
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*extract_line(char **rest);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif // GET_NEXT_LINE_H
