#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fdata
{
	char buffer[BUFFER_SIZE];
	size_t start;
	size_t end;
} t_fdata;

size_t	ft_strlen(const char *str);
void	ft_clearindex(t_fdata *index);
t_fdata	*ft_newindex(void);
t_fdata	*ft_updateindex(t_fdata *index, int fd);
char	*ft_readline(char *str, t_fdata *index);
char	*get_next_line(int fd);

#endif