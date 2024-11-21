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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	range = malloc(sizeof(int *) * (max - min));
	if (min >= max)
		return(0);
	i = 0;
	while (min < max)
	{
		*range[i] = min + i;
		i++;
	}
	return (i);
}
