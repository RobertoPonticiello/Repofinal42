/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:56:13 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:56:16 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

int	init_stacks(t_stack **a, t_stack **b, size_t nmemb)
{
	*a = create_stack(nmemb);
	if (!*a)
		return (0);
	*b = create_stack(nmemb);
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

t_stack	*create_stack(size_t nmemb)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->nums = malloc(sizeof(int) * nmemb);
	if (!tmp->nums)
		return (NULL);
	tmp->len = 0;
	return (tmp);
}

int	check_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->nums[i] > stack->nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}
