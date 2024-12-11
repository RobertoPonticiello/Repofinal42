/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:22:25 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/11 15:29:06 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isascii(int c)
{
	return(c >= 0 && c <= 127);
}
