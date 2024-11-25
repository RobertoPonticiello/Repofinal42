/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:11:05 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/25 14:21:58 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sort_args(int argc, char **argv);
void	print_args(int argc, char **argv);
int		ft_strlen(char *str);

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	sort_args(argc, argv);
	print_args(argc, argv);
	return (0);
}

void	sort_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			k = 0;
			while (argv[i][k] && argv[j][k] && argv[i][k] == argv[j][k])
				k++;
			if ((unsigned char)argv[i][k] > (unsigned char)argv[j][k])
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_args(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		write(1, argv[i], len);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
