/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:48 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/22 14:41:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void freestatic(char *staticbuffer)
{
    int i;
    i = 0; 
    while ( i < BUFFER_SIZE) {
            staticbuffer[i] = 0;
            i ++; 
     }
}
void restline(size_t  i, char *buffer , char *staticbuffer, char *therest)
{
            size_t  k;
            
            k = 0; 
            while (k < i)
            {
               
                therest[k] = buffer[k];
                k ++ ;
            }
            k = 0 ;
            while ( BUFFER_SIZE > i)
            {
                staticbuffer[k] = buffer[i];
                i ++;
                k ++;
            }
}
size_t checknewline(size_t i, size_t byte_read , char *buffer)
{
    while (i < byte_read)
        {
            if (buffer[i] == '\n')
                break;
            i++ ; 
        }
        return (i);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *stockbuffer = "";
    static char staticbuffer[BUFFER_SIZE];
    char    *line;
    char    *therest;
    size_t  byte_read;
    size_t  i = 0;

    therest = malloc(BUFFER_SIZE);
    buffer = malloc(BUFFER_SIZE);
    if (!therest)
        return NULL;
     if (!buffer)
        return NULL;
    line =  NULL;
    byte_read = read(fd, buffer, BUFFER_SIZE);
    while (byte_read  > 0)
    {
        buffer[byte_read] = '\0';
        i = checknewline ( i,byte_read ,buffer) ;
        if (i == byte_read )
        {  
            stockbuffer = ft_strjoin(stockbuffer ,staticbuffer); 
            stockbuffer = ft_strjoin(stockbuffer ,buffer);
            i = 0; 
            freestatic(staticbuffer);
            
        }  
        else 
        {
            restline (i, buffer, staticbuffer, therest) ;
            line = ft_strjoin(stockbuffer ,therest);
            break;
        }
        byte_read = read(fd, buffer, BUFFER_SIZE);
    }
   printf("%s", line);
   
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
    get_next_line(fd);

    close(fd);  // Ne pas oublier de fermer le fichier
    return 0;
}