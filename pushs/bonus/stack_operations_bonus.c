/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:55:49 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:55:54 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = tmp;
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->nums[0];
	while (i < stack->len - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = tmp;
}

void	rrotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->len - 1;
	tmp = stack->nums[stack->len - 1];
	while (i > 0)
	{
		stack->nums[i] = stack->nums[i - 1];
		i--;
	}
	stack->nums[i] = tmp;
}

void	push(t_stack *a, t_stack *b)
{
	int	num;
	int	i;
	int	j;

	if (b->len == 0)
		return ;
	num = b->nums[0];
	i = 1;
	j = a->len;
	while (i <= b->len - 1)
	{
		b->nums[i - 1] = b->nums[i];
		i++;
	}
	while (j > 0)
	{
		a->nums[j] = a->nums[j - 1];
		j--;
	}
	b->len--;
	a->len++;
	a->nums[j] = num;
}
