/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:51 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/23 13:24:27 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE  5

char	*ft_strdup( char *src);
char    *get_next_line(int fd);
char    *get_next_line(int fd);
size_t	ft_strlen(  const char *theString );
char    *ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *s, int c);
#endif