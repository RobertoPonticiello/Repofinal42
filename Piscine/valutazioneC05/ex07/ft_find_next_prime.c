/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:46:13 by kadferna          #+#    #+#             */
/*   Updated: 2024/11/19 15:04:00 by kadferna         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	l;

	l = 1;
	while (l == 1)
	{
		if (ft_is_prime(nb) == 0)
			nb++;
		else
			l = 0;
	}
	return (nb);
}
/*
int main (void)
{
	int l = ft_find_next_prime(79);
	printf("%d\n", l);
	return l;
}*/
