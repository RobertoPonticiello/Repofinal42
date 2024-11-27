/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:34:45 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/27 00:23:45 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				s = -s;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		else
			i++;
	}
	return(result * s);
}

int	main(void)
{
	printf("%d", ft_atoi("       -+---+--++151we14"));
	return(0);
}




































/*int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	num;

	i = 0;
	s = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * s);
}*/
