#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	char	str[100] = "42roma";
	int		size;

	size = ft_strlen(str);
	write (1, &(char){size + '0'}, 1);
	return (0);
}
