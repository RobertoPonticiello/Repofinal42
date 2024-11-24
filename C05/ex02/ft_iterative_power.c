/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:23:12 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/21 14:47:53 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	i = 0;
	result = nb;
	while (i <= power - 2)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

/*int	main(void)
{
	int	nb;
	int	power;
	int	result;

	nb = -5;
	power = 2;
	result = ft_iterative_power(nb, power);
	printf ("%d", result);
}*/
