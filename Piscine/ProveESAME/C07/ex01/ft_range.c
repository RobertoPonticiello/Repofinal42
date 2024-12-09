/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:20 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/27 19:25:49 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*porcodio;
	int	i;

	i = 0;
	if (min >= max)
	{
		return(NULL);
	}
	porcodio = malloc(sizeof(int) * (max - min));
	if (!porcodio)
	{
		return(NULL);
	}
	while (i < (max - min))
	{
		porcodio[i] = min;
		i++;
		min++;
	}
	return(porcodio);
}

int	main(int argc, char **argv)
{
	int	*srg;
	int	i;

	i = 0;
	srg =  ft_range(argv[1][0], argv[2][0]);
	while(i < (argv[1][0] - argv[2][0]))
	{
		printf("%d", srg[i]);
		i++;
	}
}











































