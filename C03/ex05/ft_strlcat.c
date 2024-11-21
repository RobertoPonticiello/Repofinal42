/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:18:59 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/19 20:43:25 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	len;

	i = 0;
	size_dest = 0;
	size_src = 0;
	while (dest[size_dest] != '\0')
	{
		size_dest++;
	}
	while (src[size_src] != '\0')
	{
		size_src++;
	}
	while (src[i] != '\0' && i < size - size_dest)
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = '\0';
	len = size_dest + size_src;
	return (len);
}
