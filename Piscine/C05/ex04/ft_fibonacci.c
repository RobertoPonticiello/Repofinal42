/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:03:15 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/25 13:53:45 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	i;
	int	a;
	int	b;
	int	temp;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	a = 0;
	b = 1;
	i = 2;
	while (i <= index)
	{
		temp = a + b;
		a = b;
		b = temp;
		i++;
	}
	return (b);
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
