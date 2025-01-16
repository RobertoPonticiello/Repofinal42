/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:31:18 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:29:54 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort_stack(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		push(b, a);
	if (a->len == 3)
	{
		if (a->nums[0] > a->nums[1] && a->nums[0] > a->nums[2])
			rotate(a, 1);
		else if (a->nums[1] > a->nums[0] && a->nums[1] > a->nums[2])
			rrotate(a, 1);
		if (a->nums[0] > a->nums[1])
			swap(a, 1);
	}
	while (b->len > 0)
		smart_push(a, b);
	apply_rot(a, get_min_rot(a, a->nums[get_min_num_index(a)], 1));
}

void	smart_push(t_stack *a, t_stack *b)
{
	int	num;
	int	rot;
	int	rota;

	num = get_eff_num(a, b);
	rota = get_min_rot(b, num, 1);
	rot = get_min_rot(a, num, 0);
	optimize_rot(b, &rota, a, &rot);
	apply_rot(b, rota);
	apply_rot(a, rot);
	push(a, b);
}

int	calculate_eff(t_stack *a, t_stack *b, int num)
{
	int	rota;
	int	rotb;

	rota = get_min_rot(a, num, 0);
	rotb = get_min_rot(b, num, 1);
	if (rota < 0 && rotb < 0)
	{
		if (rota < rotb)
			return (get_abs(rota));
		return (get_abs(rotb));
	}
	if (rota > 0 && rotb > 0)
	{
		if (rota > rotb)
			return (rota);
		return (rotb);
	}
	return (get_abs(rota) + get_abs(rotb));
}

int	get_eff_num(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;
	int	curr;
	int	eff;
	int	num;

	i = 0;
	num = 0;
	curr = INT_MAX;
	while (i < b->len)
	{
		tmp = b->nums[i];
		eff = calculate_eff(a, b, tmp);
		if (curr > eff)
		{
			num = tmp;
			curr = eff;
		}
		i++;
	}
	return (num);
}
