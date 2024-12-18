/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:56:46 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/14 19:17:41 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*r;
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (const char)c)
		{
			r = (char *)&string[i];
		}
		i++;
	}
	if (string[i] == (const char)c)
	{
		return((char *)&string[i]);
	}
	return(r);
}
/*
#include <stdio.h>

int main()
{
    const char *str = "Hello, world!";
    char c = 'o';
    char *result = ft_strrchr(str, c);

    if (result)
        printf("Ultima occorrenza di '%c' trovata in posizione: %ld\n", c, result - str);
    else
        printf("Carattere '%c' non trovato.\n", c);

    return 0;
}*/
