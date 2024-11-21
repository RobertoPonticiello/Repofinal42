/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:19:17 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/21 17:27:25 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int     ft_recursive_power(int nb, int power)
{
        int     result;
        int     i;

        result = nb;
        i = 0;
        if (power < 0)
                return (0);
        else if (power == 0)
                return (1);
        while (i < power - 1)
        {
                result = nb * ft_recursive_power(nb, power - 1);
                i++;
        }
        return (result);
}

/*
int     main(void)
{
        int     r;
        r = ft_recursive_power(5, 4);
        printf("%d", r);
}*/
