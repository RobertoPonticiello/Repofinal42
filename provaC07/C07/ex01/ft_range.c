/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:10:11 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/21 20:35:15 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	range = malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
/*
int	main(void)
{
	int	*result = ft_range(5, 10);
	int	i = 0;

	printf("%ls", result);

	while (i <= 10)
	{
		printf("%d", result[i]);
		i++;
	}
}*/
