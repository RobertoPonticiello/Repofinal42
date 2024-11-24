/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:03:15 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/24 15:45:49 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index < 0)
		return (-1);
	else
	{
		while (i <= index)
		{
			f = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
			i++;
		}
	}
	return (f);
}
/*
int	main(void)
{
		printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
		printf("%d\n", ft_fibonacci(2));
		printf("%d\n", ft_fibonacci(3));
		printf("%d\n", ft_fibonacci(4));
		printf("%d\n", ft_fibonacci(5));
		printf("%d\n", ft_fibonacci(6));
		printf("%d\n", ft_fibonacci(7));
		printf("%d\n", ft_fibonacci(8));
	return(0);
}*/
