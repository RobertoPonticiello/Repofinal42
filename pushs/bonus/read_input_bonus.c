/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:55:09 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:55:15 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include <stdlib.h>

static int	apply_both_op(char *op, t_stack *a, t_stack *b);
static int	apply_op(char *op, t_stack *a, t_stack *b);

int	read_input(t_stack *a, t_stack *b)
{
	char	*op;

	op = NULL;
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (!apply_op(op, a, b))
		{
			free(op);
			return (0);
		}
		free(op);
		op = NULL;
	}
	return (1);
}

static int	apply_op(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "\n"))
		return (0);
	if (!ft_strcmp(op, "sa\n"))
		swap(a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(b);
	else if (!ft_strcmp(op, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(op, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(op, "rra\n"))
		rrotate(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrotate(b);
	else
		return (apply_both_op(op, a, b));
	return (1);
}

static int	apply_both_op(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "ss\n"))
	{
		swap(b);
		swap(a);
	}
	else if (!ft_strcmp(op, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(op, "rrr\n"))
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (0);
	return (1);
}
