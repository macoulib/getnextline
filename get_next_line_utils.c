/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:43 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/23 13:17:26 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen( const char *theString )
{
	size_t	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	srclen;
	char	*srcpy;

	i = 0;
	srclen = ft_strlen(src);
	srcpy = malloc((srclen + 1) * sizeof(char));
	if (!srcpy)
		return (NULL);
	while (i < srclen)
	{
		srcpy[i] = src[i];
		i++;
	}
	srcpy[i] = '\0';
	return (srcpy);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	size_t	s1s2len;
	size_t	i;
	size_t	j;
	char	*s1s2cpy;

	i = 0;
	j = 0;
	s1s2len = ft_strlen(s1) + ft_strlen(s2);
	s1s2cpy = malloc ((s1s2len + 1) * sizeof(char));
	if (!s1s2cpy)
		return (NULL);
	while (s1[i])
	{
		s1s2cpy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s1s2cpy[i] = s2[j];
		i++;
		j ++;
	}
	s1s2cpy[i] = '\0';
	return (s1s2cpy);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}