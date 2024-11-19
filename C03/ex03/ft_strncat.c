/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:31 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/19 15:37:15 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	size(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	s;

	s = size(dest);
	i = 0;
	while (src [i] != '\0')
	{
		if (i < nb)
		{
			dest[s + i] = src[i];
			i++;
		}
		else
		{
			break;
		}
	}
	dest[s + i] = '\0';
	return (dest);
}
