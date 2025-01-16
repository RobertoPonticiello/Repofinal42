/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:25:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:31:26 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

size_t	arr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i] != NULL)
		i++;
	return (i);
}

int	handle_error(t_stack **a, t_stack **b, char ***nums)
{
	free_all(a, b, nums);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	free_all(t_stack **a, t_stack **b, char ***nums)
{
	int	i;
	int	len;

	i = 0;
	len = arr_len(*nums);
	while (i < len)
	{
		free((*nums)[i]);
		i++;
	}
	free(*nums);
	free_stack(*a);
	free_stack(*b);
}

char	**init_args(int argc, char **argv, size_t *nmemb)
{
	char	**nums;
	char	**tmp;
	int		i;

	i = 2;
	nums = ft_split(argv[1], ' ');
	if (!nums)
		return (NULL);
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		nums = arr_cat(nums, tmp);
		if (!nums)
			return (NULL);
		i++;
	}
	*nmemb = arr_len(nums);
	return (nums);
}

char	**arr_cat(char **arr1, char **arr2)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char **) * (arr_len(arr1) + arr_len(arr2)
				+ 1));
	if (!res)
		return (NULL);
	while (arr1 && arr1[i] != NULL)
	{
		res[i] = arr1[i];
		i++;
	}
	while (arr2 && arr2[j] != NULL)
	{
		res[i + j] = arr2[j];
		j++;
	}
	res[i + j] = NULL;
	free(arr1);
	free(arr2);
	return (res);
}
