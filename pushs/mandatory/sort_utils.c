/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:32:15 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:30:17 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	apply_rot(t_stack *stack, int rot)
{
	while (rot < 0)
	{
		rrotate(stack, 1);
		rot++;
	}
	while (rot > 0)
	{
		rotate(stack, 1);
		rot--;
	}
}

int	get_min_num_index(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < stack->len)
	{
		if (stack->nums[min] > stack->nums[i])
			min = i;
		i++;
	}
	return (min);
}

void	optimize_rot(t_stack *a, int *rota, t_stack *b, int *rotb)
{
	while ((*rota) < 0 && (*rotb) < 0)
	{
		rrotate_both(a, b);
		(*rota)++;
		(*rotb)++;
	}
	while ((*rota) > 0 && (*rotb) > 0)
	{
		rotate_both(a, b);
		(*rota)--;
		(*rotb)--;
	}
}

int	get_min_rot(t_stack *stack, int num, int flag)
{
	int	index;
	int	i;

	if (!flag)
		index = get_min_num_index(stack);
	else
		index = 0;
	i = 0;
	while (i < stack->len)
	{
		if (num < stack->nums[index] && !flag)
			break ;
		if (num == stack->nums[index] && flag)
			break ;
		i++;
		index++;
		if (index == stack->len)
			index = 0;
	}
	if (index < get_abs(index - stack->len))
		return (index);
	else
		return (index - stack->len);
}
