#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;
	char	*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;

	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return(dest);
}
