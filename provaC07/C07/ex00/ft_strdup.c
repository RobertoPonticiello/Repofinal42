/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:28:36 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/21 18:05:11 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while(src[i])
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	i = 0;
	if (dest == 0)
		return (0);
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}
/*
#include <stdlib.h>
#include <string.h>
int	main()
{
	char *source = "ciao";

	printf("%s\n", ft_strdup(source));
	printf("%s\n", strdup(source));
	return(0);
}*/
