/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:38 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:30:32 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_stack *stack, int to_print)
{
	int	tmp;

	tmp = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = tmp;
	if (to_print)
		ft_printf("s%c\n", stack->name);
}

void	rotate(t_stack *stack, int to_print)
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
	if (to_print)
		ft_printf("r%c\n", stack->name);
}

void	rrotate(t_stack *stack, int to_print)
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
	if (to_print)
		ft_printf("rr%c\n", stack->name);
}
