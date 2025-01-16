/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:42:48 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:29:03 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	size_t	nmemb;
	char	**nums;

	if (argc < 2)
		return (0);
	nums = init_args(argc, argv, &nmemb);
	a = NULL;
	b = NULL;
	if (nums == NULL || !init_stacks(&a, &b, nmemb))
		return (handle_error(&a, &b, &nums));
	if (!parse_args(a, nums, nmemb))
		return (handle_error(&a, &b, &nums));
	if (!check_stack(a))
		sort_stack(a, b);
	free_all(&a, &b, &nums);
	return (0);
}
