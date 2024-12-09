/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:05:56 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 19:06:07 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "matrix.h"

int matt(int size, int **matrix)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        matrix[i] = (int *)malloc(size * sizeof(int));
        if (matrix[i] == NULL)
        {
            write(1, "Memory allocation error\n", 24);
            j = 0;
            while (j < i)
            {
                free(matrix[j]);
                j++;
            }
            free(matrix);
            return (0);
        }
        i++;
    }
    return (1);
}

int **inmat(int size, int **matrix)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }
    return (matrix);
}

int **create_matrix(int size)
{
    int **matrix;

    matrix = (int **)malloc(size * sizeof(int *));
    if (matrix == NULL)
    {
        write(1, "Memory allocation error\n", 24);
        return (0);
    }
    if (!matt(size, matrix))
        return (0);
    inmat(size, matrix);
    return (matrix);
}

void free_matrix(int **matrix, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

