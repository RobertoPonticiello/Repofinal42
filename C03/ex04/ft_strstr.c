/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:43:52 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/19 16:40:13 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	fanculom;
	char	j[100];

	i = 0;
	while (str[i] != '\0' || to_find[i] != '\0')
	{ 
		if (str[i] == to_find[i])
		{
			j[fanculom] = str[i];
			fanculom++;
		}
		i++;
	}
	return(j);
}

int	main(void)
{
	char prima;
	char seconda;

	prima[100] = "dio e un maledetto";
	seconda[100] = "quel porco di dio e un maledetto";

	strstr(prima, seconda);
}
