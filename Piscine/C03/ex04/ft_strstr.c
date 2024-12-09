/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:43:52 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/19 20:46:13 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	const char	*h;
	const char	*n;

	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	while (*str)
	{
		h = str;
		n = to_find;
		while (*h != '\0' && *n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
