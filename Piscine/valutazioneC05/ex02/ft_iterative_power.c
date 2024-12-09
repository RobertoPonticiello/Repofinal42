/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:59:15 by kadferna          #+#    #+#             */
/*   Updated: 2024/11/18 18:11:29 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	if (nb == 0 || power == 0)
		return (1);
	while (power - 1 > 0)
	{
		nb *= i;
		power--;
	}
	return (nb);
}
/*
int main(void)
{
	int l = ft_iterative_power(3, 10);
	printf("%d\n", l);
	return 0;
}*/
