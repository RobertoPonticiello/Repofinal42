/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:42:10 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/11 19:44:17 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void    *ft_memset(void *ptr, int value, size_t num);

void	ft_bzero(void *ptr, size_t num)
{
	ft_memset(ptr, 0, num);
}
