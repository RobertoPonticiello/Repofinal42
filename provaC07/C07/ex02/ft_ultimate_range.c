/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:36:08 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/21 20:49:16 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	if (min >= max)
	{
        *range = NULL;
		return(0);
	}
	range = malloc(sizeof(int *) * (max - min));
	if (!range)
		return(-1);
	i = 0;
	while (min < max)
	{
		range[i] = &min;
		i++;
		min++;
	}
	return (i);
}

/*int	main(void)
{
	int	**range;
	int	result;

	result = ft_ultimate_range(range, 0, 5);
	printf("%d\n", result);
	return (0);
}*/