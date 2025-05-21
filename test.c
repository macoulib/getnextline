int main ()
{
    size_t  byte_read;
     while (byte_read = read (fd, )  > 0)
    {
        buffer[byte_read] = '\0';
        while (i < byte_read)
        {
            if (buffer[i] == '\n')
                break;
            i++ ; 
        }
        if (i == byte_read )
            stockbuffer = ft_strjoin(stockbuffer ,buffer);
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
        i = 0;
    }     
}