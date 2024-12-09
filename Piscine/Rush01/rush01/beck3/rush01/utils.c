/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:06:27 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 19:06:31 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int count_visible_from_left(int *row)
{
    int max_height;
    int count;
    int i;

    max_height = 0;
    count = 0;
    i = 0;
    while (i < SIZE)
    {
        if (row[i] > max_height)
        {
            max_height = row[i];
            count++;
        }
        i++;
    }
    return (count);
}

int count_visible_from_right(int *row)
{
    int max_height;
    int count;
    int i;

    max_height = 0;
    count = 0;
    i = SIZE - 1;
    while (i >= 0)
    {
        if (row[i] > max_height)
        {
            max_height = row[i];
            count++;
        }
        i--;
    }
    return (count);
}

