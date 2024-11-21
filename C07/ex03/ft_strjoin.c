/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:35:44 by abkhefif          #+#    #+#             */
/*   Updated: 2024/11/19 11:01:50 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	calc_totallen(int size, char **strs, char *sep)
{
	int	totallen;
	int	seplen;
	int	i;

	totallen = 0;
	i = 0;
	seplen = ft_strlen(sep);
	while (i < size)
	{
		totallen += ft_strlen(strs[i]);
		if (i < size - 1)
			totallen += seplen;
		i++;
	}
	return (totallen);
}

void	ft_cat(char *str, char *src, char *sep, int is_last)
{
	ft_strcat(str, src);
	if (!is_last)
		ft_strcat(str, sep);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*str;
	int			i;
	int			totallen;

	i = 0;
	if (size == 0)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	totallen = calc_totallen(size, strs, sep);
	str = malloc(sizeof(char) * (totallen + 1));
	if (!str)
		return (0);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_cat(str, strs[i], sep, (i == size - 1));
		i++;
	}
	return (str);
}
