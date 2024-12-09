/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:04:02 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/20 20:03:35 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	s;
	int	result;

	s = 1;
	result = 0;
	while ((*str >= '0' && *str <= '9') || *str == ' ' || *str == '+' || *str == '-')
	{
		if (*str == ' ' || *str == '+' || *str == '-')
		{
			if (*str == '-')
				s *= -1;
			str++;
		}
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
			{
				result = result * 10 + (*str - '0');
				str++;
			}
			break ;
		}
	}
	return (result * s);
}
/*
int	main(void)
{
	char	str[50] = "   ---+--+12 34ab567";
	
	printf("%d\n", ft_atoi(str));
	return (0);
}*/
