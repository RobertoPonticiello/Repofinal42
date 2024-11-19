/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmammol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:44:33 by frmammol          #+#    #+#             */
/*   Updated: 2024/11/14 18:48:02 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	t;

	t = 0;
	while (src[t] != '\0')
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	ft_strcpy(argv[1], argv[2]);
	printf("%s \n %s", argv[1], argv[2]);
	return (0);
}
