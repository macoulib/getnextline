/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:58:53 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/25 13:05:04 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd, char *staticbuffer)
{
	char	*buffer;
	int		byteread;

	buffer = malloc(BUFFER_SIZE + 1);
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byteread] = 0;
		staticbuffer = ft_strjoin(staticbuffer, buffer);
		if (!staticbuffer)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (staticbuffer);
}

char	*definedline(char *staticbuffer)
{
	size_t	i;
	size_t	slashexist;
	char	*line;

	i = 0;
	slashexist = 0;
	if (staticbuffer[i] == '\0')
		return (NULL);
	while (staticbuffer[i] != '\n' && staticbuffer[i])
		i++;
	if (staticbuffer[i] == '\n')
		slashexist = 1;
	line = malloc(i + 2);
	i = 0;
	while (staticbuffer[i] != '\n' && staticbuffer[i])
	{
		line[i] = staticbuffer[i];
		i++ ;
	}
	if (slashexist)
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*therest(char *staticbuffer)
{
	size_t	i;
	size_t	j;
	char	*therest;

	i = 0;
	j = 0;
	while (staticbuffer[i] && staticbuffer[i] != '\n')
		i++;
	if (!staticbuffer[i])
	{
		free(staticbuffer);
		return (NULL);
	}
	i++;
	therest = malloc((ft_strlen(staticbuffer) - i) + 1);
	while (staticbuffer[i])
	{
		therest[j] = staticbuffer[i];
		i++;
		j++;
	}
	therest[j] = '\0';
	free(staticbuffer);
	return (therest);
}

char	*get_next_line(int fd)
{
	static char	*staticbuffer = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	staticbuffer = readfile(fd, staticbuffer);
	line = definedline(staticbuffer);
	staticbuffer = therest(staticbuffer);
	return (line);
}

/* 
int main() {
   
    int fd = open("ex.txt", O_RDONLY);
   	printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));


   //printf(" %s \n",get_next_line(fd));
  // get_next_line(fd);
  // get_next_line(fd);

    close(fd); 
    return 0;
} */

