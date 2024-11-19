/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:39:45 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/16 16:54:19 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	col1up;
	int	col2up;
	int	col3up;
	int	col4up;
	int	col1down;
	int     col2down;
	int     col3down;
	int     col4down;
	int	row1left;
	int     row2left;
	int     row3left;
	int     row4left;
	int     row1right;
	int     row2right;
	int     row3right;
	int     row4right;

	col1up = argv[1][0];
	col2up = argv[1][2];
	col3up = argv[1][4];
	col4up = argv[1][6];
	col1down = argv[1][8];
	col2down = argv[1][10];
	col3down = argv[1][12];
	col4down = argv[1][14];
	row1left = argv[1][16];
	row2left = argv[1][18];
	row3left = argv[1][20];
	row4left = argv[1][22];
	row1right = argv[1][24];
	row2right = argv[1][26];
	row3right = argv[1][28];
	row4right = argv[1][30];

	char a;
	a = col2up + '0';
	write (1, &a, 1);
	return (0);
}
