#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
