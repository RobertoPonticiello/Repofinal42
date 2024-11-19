#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

// Funzione che gestisce la visibilità delle righe
int check_row_validity(int **grid, int constraints[16], int i)
{
    int visible_left = constraints[8 + i];
    int visible_right = constraints[12 + i];
    if (count_visible_from_left(grid[i]) != visible_left || 
        count_visible_from_right(grid[i]) != visible_right)
    {
        return (0);
    }
    return (1);
}

// Funzione che gestisce la visibilità delle colonne
int check_column_validity(int **grid, int constraints[16], int j)
{
    int max_height = 0;
    int count_up = 0, count_down = 0;
    int col_up = constraints[j];
    int col_down = constraints[4 + j];
    int i = 0;
    
    // Controlla visibilità dalla parte superiore
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
    // Controlla visibilità dalla parte inferiore
    while (i >= 0)
    {
        if (grid[i][j] > max_height)
        {
            max_height = grid[i][j];
            count_down++;
        }
        i--;
    }

    return (count_up == col_up && count_down == col_down);
}

// Funzione principale di validazione
int is_valid(int **grid, int constraints[16])
{
    int i, j;
    
    for (i = 0; i < SIZE; i++)
    {
        if (!check_row_validity(grid, constraints, i))
            return (0);
    }

    for (j = 0; j < SIZE; j++)
    {
        if (!check_column_validity(grid, constraints, j))
            return (0);
    }

    return (1);
}

// Funzione di risoluzione
int solve_column(int **grid, int row, int col, int constraints[16])
{
    if (col == SIZE)
    {
        col = 0;
        row++;
        if (row == SIZE)
            return (1);
    }

    if (grid[row][col] != 0)
        return (solve_column(grid, row, col + 1, constraints));

    for (int value = 1; value <= SIZE; value++)
    {
        grid[row][col] = value;
        if (is_valid(grid, constraints) && solve_column(grid, row, col + 1, constraints))
            return (1);
        grid[row][col] = 0;  // Backtrack
    }

    return (0);
}

int solve(int **grid, int row, int col, int constraints[16])
{
    return solve_column(grid, row, col, constraints);
}

