/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:18:45 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 14:15:52 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putlchar(int c, int *count, t_format *format)
{
	if (format)
	{
		if (ft_strchr(format->flags, '-'))
		{
			ft_putlchar(c, count, NULL);
			ft_putlnchar(' ', format->width - 1, count);
			return ;
		}
		ft_putlnchar(' ', format->width - 1, count);
	}
	ft_putchar_fd(c, 1);
	(*count)++;
}
