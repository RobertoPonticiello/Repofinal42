/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:10:58 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/13 22:44:49 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (!dest && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + i + 1)
}



#include <stddef.h> // Per size_t

size_t strlcat(char *dst, const char *src, size_t size) {
    size_t dst_len = 0;
    size_t src_len = 0;
    size_t i = 0;

    // Calcolare la lunghezza di `dst` senza superare `size`
    while (dst_len < size && dst[dst_len] != '\0') {
        dst_len++;
    }

    // Calcolare la lunghezza di `src`
    while (src[src_len] != '\0') {
        src_len++;
    }

    // Se il buffer è pieno o troppo piccolo, restituisci la lunghezza combinata
    if (dst_len >= size) {
        return size + src_len;
    }

    // Aggiungi i caratteri da `src` a `dst`, rispettando i limiti del buffer
    while (i < src_len && dst_len + i < size - 1) {
        dst[dst_len + i] = src[i];
        i++;
    }

    // Aggiungi il terminatore null
    if (dst_len + i < size) {
        dst[dst_len + i] = '\0';
    }

    // Restituisci la lunghezza combinata di `dst` e `src` (senza troncamento)
    return dst_len + src_len;
}




#include<stdio.h>

int	main()
{
	char	dest[100] = "pprcoddeno";
	char	src[100] = "cheppaccman";
	printf("%s", ft_strlcat(dest, src, 20);
	return(0);
}
