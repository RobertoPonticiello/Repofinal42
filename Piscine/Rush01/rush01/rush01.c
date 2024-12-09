/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:07:04 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 17:56:51 by frmammol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

// Function to dynamically create a matrix using malloc
int	**create_matrix(int size)
{
	int	**matrix;

	/*Allocate memory for an array of pointers (rows)*/
	matrix = (int **)malloc(size * sizeof(int *));
	if (matrix == NULL)
	{
		write(1, "Memory allocation error\n", 24);
		return (0);
	}
	/*Allocate memory for each row*/
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int *)malloc(size * sizeof(int));
		if (matrix[i] == NULL)
		{
			write(1, "Memory allocation error\n", 24);
			/* Free previously allocated memory in case of error */
			for (int j = 0; j < i; j++)
			{
				free(matrix[j]);
			}
			free(matrix);
			return (NULL);
		}
	}
	/*Initialize matrix with zeros*/
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return (matrix);
}
/*Function to free the dynamically allocated matrix*/
void	free_matrix(int **matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}
/*Function to print the grid*/
void	print_grid(int **grid)
{
	char	c;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < SIZE - 1)
			{
				write(1, " ", 1);
			}
		}
		write(1, "\n", 1);
	}
}
/* Function to count visible skyscrapers from the left*/
int	count_visible_from_left(int *row)
{
	int	max_height;
	int	count;

	max_height = 0;
	count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			count++;
		}
	}
	return (count);
}
/* Function to count visible skyscrapers from the right */
int	count_visible_from_right(int *row)
{
	int	max_height;
	int	count;

	max_height = 0;
	count = 0;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			count++;
		}
	}
	return (count);
}
// Function to check if the grid meets the constraints
int	is_valid(int **grid, int constraints[16])
{
	int	visible_left;
	int	visible_right;
	int	max_height;
	int	count_up;
	int	count_down;

	/* Check rows */
	for (int i = 0; i < SIZE; i++)
	{
		int row_left = constraints[8 + i];   /* Left constraints */
		int row_right = constraints[12 + i]; /* Right constraints */
		visible_left = count_visible_from_left(grid[i]);
		visible_right = count_visible_from_right(grid[i]);
		if (visible_left != row_left || visible_right != row_right)
		{
			return (0);
		}
	}
	/* Check columns */
	for (int j = 0; j < SIZE; j++)
	{
		int col_up = constraints[j];       /* Top constraints */
		int col_down = constraints[4 + j]; /* Bottom constraints*/
		max_height = 0;
		count_up = 0;
		count_down = 0;
		/* Count visibility from top */
		for (int i = 0; i < SIZE; i++)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				count_up++;
			}
		}
		/* Count visibility from bottom */
		max_height = 0;
		for (int i = SIZE - 1; i >= 0; i--)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				count_down++;
			}
		}
		if (count_up != col_up || count_down != col_down)
			return (0);
	}
	return (1);
}
/* function to check for duplicate numbers in a row */
int	check_row(int **grid, int row, int num)
{
	for (int col = 0; col < SIZE; col++)
	{
		if (grid[row][col] == num)
			return (0);
	}
	return (1);
}
/* Function to check for duplicate numbers in a column */
int	check_col(int **grid, int col, int num)
{
	for (int row = 0; row < SIZE; row++)
	{
		if (grid[row][col] == num)
			return (0);
	}
	return (1);
}
/* Backtracking function to solve the puzzle */
int	solve(int **grid, int row, int col, int constraints[16])
{
	int	next_row;
	int	next_col;

	if (row == SIZE)
	{
		return (is_valid(grid, constraints));
	}
	next_row = (col == SIZE - 1) ? row + 1 : row;
	next_col = (col == SIZE - 1) ? 0 : col + 1;
	for (int num = 1; num <= SIZE; num++)
	{
		if (check_row(grid, row, num) && check_col(grid, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, next_row, next_col, constraints))
			{
				return (1);
			}
			grid[row][col] = 0;
		}
	}
	return (0);
}

// Function to parse input and validate constraints
int	parse_input(char *input, int constraints[16])
{
	for (int i = 0; i < 16; i++)
	{
		if (input[i * 2] < '1' || input[i * 2] > '4')
		{
			return (0); // Error if value is not between '1' and '4'
		}
		constraints[i] = input[i * 2] - '0';
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	constraints[16];
	int	**grid;

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
