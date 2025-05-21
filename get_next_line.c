/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:48 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/21 18:45:47 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char    *get_next_line(int fd)
{
    char    *buffer;
    char    *stockbuffer = "";
    //static char *staticbuffer;
    char    *line;
    char    *restant;
    size_t  byte_read;
    size_t  i = 0;
    size_t  k = 0;

    restant = malloc(BUFFER_SIZE);
    buffer = malloc(BUFFER_SIZE);
    if (!restant)
        return NULL;
     if (!buffer)
        return NULL;
    line =  NULL;
   byte_read = read(fd, buffer, BUFFER_SIZE);
   //staticbuffer = ft_strdup(buffer);
    while (byte_read  > 0)
    {
        buffer[byte_read] = '\0';
        while (i < byte_read)
        {
            if (buffer[i] == '\n')
                break;
            i++ ; 
        }
        if (i == byte_read )
        {
           stockbuffer = ft_strjoin(stockbuffer ,buffer);
            i = 0;  
        }  
        else 
        {
            while (k < i)
            {
                restant[k] = buffer[k];
                k ++ ;
            }
           
            restant[k] ='\0';
            line = ft_strjoin(stockbuffer ,restant);
            break;
        }
        byte_read = read(fd, buffer, BUFFER_SIZE);
    }
    printf("%s \n", line);
   
    free(buffer); 
    return line;
}

int main(void) {
    int fd = open("ex.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

   
    get_next_line(fd);
    get_next_line(fd);
    close(fd);  // Ne pas oublier de fermer le fichier
    return 0;
}