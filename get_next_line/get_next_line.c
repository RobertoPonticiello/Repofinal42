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

t_fdata *ft_updateindex(t_fdata *index, int fd)
{
    ssize_t bytes_read;

    // Controlla se dobbiamo leggere nuovi dati
    if (index->start >= index->end)
    {
        bytes_read = read(fd, index->buffer, BUFFER_SIZE);
        if (bytes_read <= 0) // EOF o errore
        {
            ft_clearindex(index);
            return (NULL); // Restituisci NULL se non ci sono più dati
        }

        // Aggiorna i campi start ed end
        index->start = 0;
        index->end = bytes_read;
    }

    return index;
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