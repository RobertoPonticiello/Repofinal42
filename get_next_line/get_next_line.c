#include "get_next_line.h"

void    ft_clearindex(t_fdata *index)
{
    if (index)
        free(index);
}


t_fdata *ft_newindex(int fd)
{
    t_fdata *result;
    
    result = malloc(sizeof(t_fdata));
    if (!result)
        return (NULL);
    result->start = 0;
    result->end = 0;
    return(result);
}

t_fdata  *ft_updateindex(t_fdata *index)
{

}

char    *get_next_line(int fd)
{
    static t_fdata *fd_index[1024];
    char    *str = NULL;

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!fd_index[fd])
    {
        fd_index[fd] = ft_newindex(fd);
        if (!fd_index[fd])
            return (NULL);
    }
    fd_index[fd] = ft_updateindex(fd_index[fd]);

    return (str);
}