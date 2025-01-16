/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:47:25 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:26:43 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	rrotate_both(t_stack *a, t_stack *b)
{
	rrotate(a, 0);
	rrotate(b, 0);
	ft_printf("rrr\n");
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
	ft_printf("p%c\n", a->name);
}
