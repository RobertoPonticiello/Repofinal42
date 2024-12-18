/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:10:29 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/14 18:55:01 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int c)
{
	int	i;
	
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)c)
			return((char *)c);
		i++;
	}
	if (string[i] == (char)c)
		return((char *)c);
	return(NULL);
}
