/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:18:20 by kadferna          #+#    #+#             */
/*   Updated: 2024/11/19 14:24:02 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	g;

	g = 0;
	if (nb <= 0)
		return (0);
	while (g * g < nb)
		g++;
	if (g * g == nb)
		return (g);
	return (0);
}
/*
int main(void)
{
	int l = ft_sqrt(25);
	printf("%d\n", l);
	return 0;
}*/
