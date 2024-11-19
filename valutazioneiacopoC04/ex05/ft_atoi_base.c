/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:58 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/13 15:01:13 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int size_base)
{
	int	result;
	int	mult;
	int	index;

	mult = 1;
	result = 0;
	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			mult = -mult;
		index++;
	}
	while (is_in_str(base, str[index]))
	{
		result = (result * size_base) + (is_in_str(base, str[index]) - 1);
		index++;
	}
	return (result * mult);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32 || base[i] == 127)
			return (0);
		i++;
	}
	if (has_duplicates(base))
		return (0);
	if (i <= 1)
		return (0);
	return (ft_atoi(str, base, i));
}

// int main(){
// 	char str[] = "1000000";
// 	char base[] = "01";
// 	printf("%d\n", ft_atoi_base(str, base));
// }
