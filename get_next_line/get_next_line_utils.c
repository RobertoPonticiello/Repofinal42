#include "get_next_line.h"

void    ft_clearindex(t_fdata *index)
{
    if (index)
        free(index);
}

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str && str[len])
        len++;
    return len;
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
        if (bytes_read <= 0)
        {
            index->start = 0;
            index->end = 0;
            return (index);
        }
        index->start = 0;
        index->end = bytes_read;
    }
    return (index);
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t len1 = 0, len2 = 0;
    size_t i = 0, j = 0;
    char *result;

    if (s1)
        while (s1[len1])
            len1++;
    while (s2[len2])
        len2++;
    result = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return NULL;

    while (i < len1) {
        result[i] = s1[i];
        i++;
    }
    while (j < len2) {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    if (s1)
        free(s1);
    return result;
}


char *ft_readline(char *str, t_fdata *index) {
    size_t i = 0;
    size_t j = 0;
    char *temp;

    while (index->start + i < index->end && index->buffer[index->start + i] != '\n') {
        i++;
    }
    temp = malloc(sizeof(char) * (i + 2));
    if (!temp)
        return NULL;
    while (j < i) {
        temp[j] = index->buffer[index->start + j];
        j++;
    }
    if (index->start + i < index->end && index->buffer[index->start + i] == '\n') {
        temp[j++] = '\n';
    }
    temp[j] = '\0';
    index->start += i + (index->start + i < index->end && index->buffer[index->start + i] == '\n' ? 1 : 0);
    str = ft_strjoin(str, temp);
    free(temp);
    return str;
}


