/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:24:02 by abkhefif          #+#    #+#             */
/*   Updated: 2024/11/20 13:25:36 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			words++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (words);
}

char	*copy_word(char *str, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		mot;
	int		len;
	int		index;

	mot = 0;
	index = count_words(str, charset);
	dest = malloc(sizeof(char *) * (index + 1));
	if (!str || !charset || !dest)
		return (0);
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			len = 0;
			while (str[len] && !is_sep(str[len], charset))
				len++;
			dest[mot++] = copy_word(str, len);
			str += len;
		}
	}
	dest[mot] = NULL;
	return (dest);
}
