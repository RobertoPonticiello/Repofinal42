/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:54:53 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 23:54:54 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stddef.h>

typedef struct s_stack
{
	int	*nums;
	int	len;
}		t_stack;

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	push(t_stack *a, t_stack *b);

char	**init_args(int argc, char **argv, size_t *nmemb);
char	**arr_cat(char **arr1, char **arr2);
size_t	arr_len(char **arr);
int		handle_error(t_stack **a, t_stack **b, char ***nums);
void	free_all(t_stack **a, t_stack **b, char ***nums);

int		init_stacks(t_stack **a, t_stack **b, size_t nmemb);
t_stack	*create_stack(size_t nmemb);
int		check_stack(t_stack *stack);
void	free_stack(t_stack *stack);

int		parse_args(t_stack *stack, char **argv, size_t nmemb);
int		read_input(t_stack *a, t_stack *b);

#endif
