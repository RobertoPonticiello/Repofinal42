/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:34:53 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/15 16:07:20 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libstd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*str;

	size1 = 0;
	size2 = 0;
	while (s1[size1] != '\0')
	{
		size1++;
	}
	while (s2[size2] != '\0')
	{
		size2++;
	}
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (NULL);
	str[size1 + size2] = '\0';
	while (i < size1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (size1 + size2))
	{
		str[i] = s2[i];
		i++;
	}
	return(str);
}

int	main()
{
	printf("%s", ft_strjoin("che palle", " sta cazzo di societa"));
	return(0);
}
