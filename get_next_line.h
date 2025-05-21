/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:51 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/21 17:25:18 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE  3

char	*ft_strdup( char *src);
char    *get_next_line(int fd);
char    *get_next_line(int fd);
size_t	ft_strlen(  const char *theString );
char    *ft_strjoin(char  *s1, char  *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest,  void *src, size_t n);

#endif