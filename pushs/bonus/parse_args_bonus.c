/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:55:04 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:55:05 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include <limits.h>
#include <stddef.h>

static int	validate_arg(char *num, t_stack *stack);
static void	handle_sign(char c, int *sign, int *index);
static int	ft_isint(long num);
static int	check_duplicate(int num, t_stack *stack);

int	parse_args(t_stack *stack, char **nums, size_t nmemb)
{
	size_t	i;
	char	*num;

	i = 0;
	if (!(*nums))
		return (0);
	while (i < nmemb)
	{
		num = nums[i];
		if (!validate_arg(num, stack))
			return (0);
		stack->nums[i] = ft_atoi(num);
		stack->len++;
		i++;
	}
	return (1);
}

static int	validate_arg(char *num, t_stack *stack)
{
	int		i;
	long	value;
	int		sign;

	if (ft_strlen(num) == 0)
		return (0);
	value = 0;
	sign = 1;
	i = 0;
	handle_sign(num[i], &sign, &i);
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]))
			return (0);
		value = (value * 10) + num[i] - '0';
		if (!ft_isint(value * sign))
			return (0);
		i++;
	}
	value *= sign;
	return (check_duplicate((int)value, stack));
}

static void	handle_sign(char c, int *sign, int *index)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign *= -1;
		(*index)++;
	}
}

static int	ft_isint(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	check_duplicate(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (num == stack->nums[i])
			return (0);
		i++;
	}
	return (1);
}
