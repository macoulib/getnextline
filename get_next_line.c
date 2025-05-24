/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:58:53 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/24 16:53:04 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"



char    *readfile (int fd, char *staticbuffer)
{
    char *buffer;
    size_t  byteread = 1;

    buffer = malloc(BUFFER_SIZE);
    while (byteread > 0)
    {
        byteread = read(fd, buffer, BUFFER_SIZE);
        buffer[byteread] = '\0';
        if (byteread < 0)
        {
            free(buffer);
            return (NULL);
        }
        staticbuffer = ft_strjoin(staticbuffer,buffer);
        if(ft_strchr(buffer,'\n'))
            break;
        free(buffer);
    }
    return (staticbuffer);
    
}

char    *definedline(char *staticbuffer)
{
    size_t  i;
    char    *line;
    
    i = 0;
    while (staticbuffer[i] != '\n' && staticbuffer[i])
        i++;
    line = malloc( i + 2);

    i = 0;
    while (staticbuffer[i] != '\n' && staticbuffer[i])
    {
        line[i] = staticbuffer[i];
        i++ ;
    }
    line[i] = '\n';
    line[i + 1] = '\0';
    return (line);
} 

char    *get_next_line(int fd)
{
    char    static *staticbuffer;
    char    *line ;
    
    staticbuffer = malloc(1024);
    if(!staticbuffer)
        return (NULL);
    staticbuffer = readfile(fd,staticbuffer);
    line = definedline(staticbuffer);
    return (line);
}





int main(void) {
    int fd = open("ex.txt", O_RDONLY);
    
    //printf("%s \n",get_next_line(fd));
   // printf("%s \n",get_next_line(fd));
  get_next_line(fd);
    close(fd); 
    return 0;
}