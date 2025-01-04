#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_fdata *fd_index[1024];
    char    *str = NULL;

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!fd_index[fd])
    {
        fd_index[fd] = ft_newindex();
        if (!fd_index[fd])
            return (NULL);
    }
    fd_index[fd] = ft_updateindex(fd_index[fd], fd);
    if (!fd_index[fd])
        return (NULL);
    str = ft_readline(str, fd_index[fd]);
    return (str);
}


int main()
{
    char *fd;

    int i = open("file.txt", O_RDONLY);
    fd = get_next_line(i);
    printf("%s", fd);
    fd = get_next_line(i);
    printf("%s", fd);
    fd = get_next_line(i);
    printf("%s", fd);
    fd = get_next_line(i);
    printf("%s", fd);
    fd = get_next_line(i);
    printf("%s", fd);
    return(0);
}