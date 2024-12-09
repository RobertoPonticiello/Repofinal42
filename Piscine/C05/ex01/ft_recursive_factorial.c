/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:29:58 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/24 15:30:03 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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
