/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:20 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/13 14:42:19 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(long long int nb, int n_base, char *c_base)
{
	char	digit;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= n_base)
	{
		ft_putnbr(nb / n_base, n_base, c_base);
	}
	digit = c_base[nb % n_base];
	write(1, &digit, 1);
}

int	has_duplicates(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		if (base[i] <= 32 || base[i] == 127)
			return ;
		i++;
	}
	if (has_duplicates(base))
		return ;
	if (i <= 1)
		return ;
	ft_putnbr((long long int)nbr, i, base);
}

// int main()
// {
// 	int nbr = 1024;
// 	char base[] = "0123456789abcdef";
// 	ft_putnbr_base(nbr, base);
// 	printf("\n");
// }
