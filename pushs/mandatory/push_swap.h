/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:48:00 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/13 22:32:21 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack
{
	char	name;
	int		*nums;
	int		top;
	int		len;
}			t_stack;

void		swap(t_stack *stack, int to_print);
void		rotate(t_stack *stack, int to_print);
void		rrotate(t_stack *stack, int to_print);
void		push(t_stack *a, t_stack *b);
void		swap_both(t_stack *a, t_stack *b);
void		rotate_both(t_stack *a, t_stack *b);
void		rrotate_both(t_stack *a, t_stack *b);

char		**init_args(int argc, char **argv, size_t *nmemb);
char		**arr_cat(char **arr1, char **arr2);
size_t		arr_len(char **arr);
int			handle_error(t_stack **a, t_stack **b, char ***nums);
void		free_all(t_stack **a, t_stack **b, char ***nums);

int			init_stacks(t_stack **a, t_stack **b, size_t nmemb);
t_stack		*create_stack(size_t nmemb, char name);
int			check_stack(t_stack *stack);
void		free_stack(t_stack *stack);

void		sort_stack(t_stack *a, t_stack *b);
void		smart_push(t_stack *a, t_stack *b);
int			get_abs(int n);
int			get_min_num_index(t_stack *stack);
int			calculate_eff(t_stack *a, t_stack *b, int num);
int			get_eff_num(t_stack *a, t_stack *b);
int			get_min_rot(t_stack *stack, int num, int flag);
void		optimize_rot(t_stack *a, int *rota, t_stack *b, int *rotb);
void		apply_rot(t_stack *stack, int rot);

int			parse_args(t_stack *stack, char **argv, size_t nmemb);

#endif
