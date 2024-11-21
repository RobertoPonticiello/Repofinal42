/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:52:09 by abkhefif          #+#    #+#             */
/*   Updated: 2024/11/19 10:58:24 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(sizeof(int) * (max - min + 1));
	if (!tab)
		return (0);
	if (min >= max)
	{
		return (0);
	}
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
