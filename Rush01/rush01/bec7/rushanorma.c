/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushanorma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:18:04 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/17 18:49:16 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

int	matt(int size, int **matrix)
{
	int	i;
	int	j;

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

int	**inmat(int size, int **matrix)
{
	int	i;
	int	j;

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

int	**create_matrix(int size)
{
	int	**matrix;

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

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_grid(int **grid)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	count_visible_from_left(int *row)
{
	int	max_height;
	int	count;
	int	i;

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

int	count_visible_from_right(int *row)
{
	int	max_height;
	int	count;
	int	i;

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

int	is_valid(int **grid, int constraints[16])
{
	int	visible_left;
	int	visible_right;
	int	max_height;
	int	count_up;
	int	count_down;
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		// Utilizzare i vincoli per le righe
		visible_left = constraints[8 + i];
		visible_right = constraints[12 + i];
		if (count_visible_from_left(grid[i]) != visible_left ||
			count_visible_from_right(grid[i]) != visible_right)
		{
			return (0);
		}
		i++;
	}

	j = 0;
	while (j < SIZE)
	{
		// Utilizzare i vincoli per le colonne
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
		if (count_up != constraints[j] || count_down != constraints[4 + j])
			return (0);
		j++;
	}
	return (1);
}

int	check_row(int **grid, int row, int num)
{
	int	col;

	col = 0;
	while (col < SIZE)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	check_col(int **grid, int col, int num)
{
	int	row;

	row = 0;
	while (row < SIZE)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	solve(int **grid, int row, int col, int constraints[16])
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == SIZE)
	{
		return (is_valid(grid, constraints));
	}
	next_row = (col == SIZE - 1) ? row + 1 : row;
	next_col = (col == SIZE - 1) ? 0 : col + 1;
	num = 1;
	while (num <= SIZE)
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
		num++;
	}
	return (0);
}

int	parse_input(char *input, int constraints[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (input[i * 2] < '1' || input[i * 2] > '4')
		{
			return (0);
		}
		constraints[i] = input[i * 2] - '0';
		i++;
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

