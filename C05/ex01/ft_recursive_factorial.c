
#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	pr;

	if (nb == 1)
		return (1);
	else if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	pr = nb * ft_recursive_factorial(nb - 1);
	return (pr);
}

/*int	main(void)
{
	int	i = 5;
	int	f;

	f = ft_recursive_factorial(i);
	printf("%d", f);
}*/
