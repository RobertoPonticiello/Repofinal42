/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:03:02 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/25 20:03:27 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ts(int size, char **strs)
{
	int	j;
	int	size_str;

	size_str = 0;
	j = 0;
	while (j < size)
	{
		size_str += ft_strlen(strs[j]);
		j++;
	}
	return (size_str);
}

void	ft_strcpy_into(char *dest, char *src, int *k)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*k] = src[i];
		i++;
		(*k)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		j;
	int		k;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		if (str)
			str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (ts(size, strs) + size * ft_strlen(sep)));
	if (!str)
		return (NULL);
	j = 0;
	k = 0;
	while (j < size)
	{
		ft_strcpy_into(str, strs[j], &k);
		if (j < size - 1)
			ft_strcpy_into(str, sep, &k);
		j++;
	}
	str[k] = '\0';
	return (str);
}
