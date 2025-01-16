/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:18:45 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 14:21:18 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	assign_flags(int *minus, int *zero, int *dot, t_format *format);

void	print_front_padding(int len, int *count, t_format *format)
{
	int	minus_flag;
	int	zero_flag;
	int	dot_flag;

	assign_flags(&minus_flag, &zero_flag, &dot_flag, format);
	if ((!minus_flag && !zero_flag) || (dot_flag && zero_flag && !minus_flag))
		ft_putlnchar(' ', format->width - ft_maxint(len, format->precision),
			count);
}

void	print_middle_padding(int len, int *count, t_format *format)
{
	int	minus_flag;
	int	zero_flag;
	int	dot_flag;

	assign_flags(&minus_flag, &zero_flag, &dot_flag, format);
	if (zero_flag && !minus_flag && !dot_flag)
		ft_putlnchar('0', format->width - len, count);
	if (dot_flag)
		ft_putlnchar('0', format->precision - len, count);
}

void	print_back_padding(int len, int *count, t_format *format)
{
	if (ft_strchr(format->flags, '-') != NULL)
		ft_putlnchar(' ', format->width - ft_maxint(len, format->precision),
			count);
}

static void	assign_flags(int *minus, int *zero, int *dot, t_format *format)
{
	*minus = ft_strchr(format->flags, '-') != NULL;
	*dot = ft_strchr(format->flags, '.') != NULL;
	*zero = ft_strchr(format->flags, '0') != NULL;
}
