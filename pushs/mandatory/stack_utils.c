/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:41:01 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:31:43 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	init_stacks(t_stack **a, t_stack **b, size_t nmemb)
{
	*a = create_stack(nmemb, 'a');
	if (!*a)
		return (0);
	*b = create_stack(nmemb, 'b');
	if (!*b)
	{
		free_stack(*a);
		return (0);
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->nums);
	free(stack);
}

t_stack	*create_stack(size_t nmemb, char name)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->nums = malloc(sizeof(int) * nmemb);
	if (!tmp->nums)
		return (NULL);
	tmp->len = 0;
	tmp->name = name;
	return (tmp);
}

int	check_stack(t_stack *stack)
{
	int	i;
	int	is_ordered;

	i = 0;
	is_ordered = 1;
	while (i < stack->len - 1)
	{
		if (stack->nums[i] > stack->nums[i + 1])
		{
			is_ordered = 0;
			break ;
		}
		i++;
	}
	while (i < stack->len - 1)
	{
		if (stack->nums[i] > stack->nums[i + 1])
			return (0);
		i++;
	}
	if (stack->nums[0] < stack->nums[i] && !is_ordered)
		return (0);
	return (1);
}
