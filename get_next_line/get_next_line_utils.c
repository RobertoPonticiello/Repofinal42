#include "get_next_line.h"

void    ft_clearindex(t_fdata *index)
{
    if (index)
        free(index);
}

t_fdata *ft_newindex(void)
{
    t_fdata *result;
    
    result = malloc(sizeof(t_fdata));
    if (!result)
        return (NULL);
    result->start = 0;
    result->end = 0;
    return(result);
}

t_fdata *ft_updateindex(t_fdata *index, int fd)
{
    ssize_t bytes_read;

    if (index->start >= index->end)
    {
        bytes_read = read(fd, index->buffer, BUFFER_SIZE);
        if (bytes_read == 0) 
        {
            index->end = index->start;
            return (index);
        }
        if (bytes_read < 0) 
        {
            ft_clearindex(index);
            return (NULL);
        }
        index->start = 0;
        index->end = bytes_read;
    return index;
}

char    *ft_readline(char *str, t_fdata *index)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (index->start + i < index->end && index->buffer[index->start + i] != '\n')
        i++;
    str = malloc(sizeof(char) * (i + 2));
    if(!str)
        return (NULL);
    
    while (j < i)
    {
        str[j] = index->buffer[index->start + j];
        j++;
    }
    if (index->start + i < index->end && index->buffer[index->start + i] == '\n')
        str[j++] = '\n';
    str[j] = '\0';
    index->start += i + (index->start + i < index->end && index->buffer[index->start + i] == '\n' ? 1 : 0);
    return (str);
}
