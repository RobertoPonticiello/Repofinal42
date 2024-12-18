/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:28:00 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/15 17:44:08 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlist.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return(NULL);
	str[i] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	return(str);
}
/*
int	main()
{

}*/
