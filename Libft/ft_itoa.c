/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:15:07 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/20 12:10:58 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		len;
	int		sign;

	len = (n <= 0);
	temp = n;
	if (n < 0)
	{
		sign = -1;
	}
	else
		sign = 1;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		len--;
		result[len] = '0' + (n % 10) * sign;
		n /= 10;
		while (len == 1 && sign == -1)
		{
			result[0] = '-';
			break ;
		}
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-452));
	return (0);
}
