/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:08:56 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 19:09:02 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

/* Funzione che crea la matrice */
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

/* Funzione che inizializza la matrice a 0 */
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

/* Funzione che crea una matrice di interi */
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

/* Funzione che libera la memoria della matrice */
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

/* Funzione che stampa la matrice */
void print_grid(int **grid)
{
    char c;
    int i;
    int j;

    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < SIZE - 1)
            {
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

/* Funzione che conta il numero di valori visibili da sinistra */
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

/* Funzione che conta il numero di valori visibili da destra */
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

/* Funzione che verifica la validità delle soluzioni */
int is_valid(int **grid, int constraints[16])
{
    int visible_left;
    int visible_right;
    int max_height;
    int count_up;
    int count_down;
    int i;
    int j;

    i = 0;
    while (i < SIZE)
    {
        int row_left = constraints[8 + i];
        int row_right = constraints[12 + i];
        visible_left = count_visible_from_left(grid[i]);
        visible_right = count_visible_from_right(grid[i]);
        if (visible_left != row_left || visible_right != row_right)
        {
            return (0);
        }
        i++;
    }

    j = 0;
    while (j < SIZE)
    {
        int col_up = constraints[j];
        int col_down = constraints[4 + j];
        max_height = 0;
        count_up = 0;
        count_down = 0;
        i = 0;
        while (i < SIZE)
        {
            if (grid[i][j] > max_height)
            {
                max_height = grid[i][j];
                count_up++;
            }
            i++;
        }
        max_height = 0;
        i = SIZE - 1;
        while (i >= 0)
        {
            if (grid[i][j] > max_height)
            {
                max_height = grid[i][j];
                count_down++;
            }
            i--;
        }
        if (count_up != col_up || count_down != col_down)
            return (0);
        j++;
    }
    return (1);
}

/* Funzione che esegue il parsing dell'input */
int parse_input(char *input, int constraints[16])
{
    int i;
    
    i = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= '1' && input[i] <= '4')
        {
            constraints[i] = input[i] - '0';
        }
        else
        {
            return (0);
        }
        i++;
    }
    return (1);
}

/* Funzione principale */
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

