# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_fdata
{
    char buffer[BUFFER_SIZE];
    size_t start;
    size_t end;
}   t_fdata;


#endif