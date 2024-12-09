/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:46:24 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/24 15:46:31 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb == 0)
		return (1);
	while (nb != 1)
	{
		result = result * (nb - 1);
		nb--;
	}
	return (result);
}

/*int	main(void)
{
	int	n;
	int	f;
	n = 5;

	f = ft_iterative_factorial(n);
	printf("%d", f);
}*/
