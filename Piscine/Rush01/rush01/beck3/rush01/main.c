/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:05:37 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 19:05:42 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "matrix.h"
#include "utils.h"

#define SIZE 4

int main(int argc, char *argv[])
{
    int constraints[16];
    int **grid;

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    grid = create_matrix(SIZE);
    if (grid == NULL)
    {
        return (1);
    }
    if (!parse_input(argv[1], constraints))
    {
        write(1, "Error\n", 6);
        free_matrix(grid, SIZE);
        return (1);
    }
    if (solve(grid, 0, 0, constraints))
    {
        print_grid(grid);
    }
    else
    {
        write(1, "Error\n", 6);
    }
    free_matrix(grid, SIZE);
    return (0);
}

