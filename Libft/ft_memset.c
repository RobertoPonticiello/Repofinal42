/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:02:11 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/11 19:26:30 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *p;
	size_t	i;

	i = 0;
	p= (unsigned char *)ptr;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return ptr;
}
