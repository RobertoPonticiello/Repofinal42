/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:08 by kadferna          #+#    #+#             */
/*   Updated: 2024/11/19 14:42:58 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	l;

	l = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (l >= 3 && l < nb)
	{
		if (nb % l == 0)
			return (0);
		l++;
	}
	return (1);
}
/*
int main(void)
{
	int l = ft_is_prime(9);
	printf("%d\n", l);
	return 0;
}*/
