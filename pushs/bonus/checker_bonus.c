/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:54:44 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:54:46 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

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
	if (!read_input(a, b))
		return (handle_error(&a, &b, &nums));
	if (check_stack(a) && b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&a, &b, &nums);
	return (0);
}
