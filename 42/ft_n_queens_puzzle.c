/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens_puzzle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <zzz@yyy>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/01/01 00:00:00 by dmanoel-          #+#    #+#             */
/*   Updated: 9999/12/31 23:59:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********
 * N queen by phrxn ;D. Enjoy it!
 *
 * This method ft_n_queens_puzzle(void); prints the queen's position on the
 * board's column..
 * 
 * E.g: 4x4 board:
 *
 *    c0 c1 c2 c3        c0 c1 c2 c3 
 * r0|  |  |Q2|  |    r0|  |Q1|  |  |
 * r1|Q0|  |  |  |    r1|  |  |  |Q3|
 * r1|  |  |  |Q3|    r2|Q0|  |  |  |
 * r1|  |Q1|  |  |    r3|  |  |Q2|  |
 *  
 * Output:
 * 	1302
 * 	2031
 *
 *******/

#include <unistd.h>

//board size, in this case 10x10
//the board size must be a value >= 4!
#define BOARD_S 10

//fill a board... to remove memory garbage and aux the print_board method.
#define BOARD_F 'X'

int		ft_n_queens_puzzle(void);

void	queen_backtracking(char board[BOARD_S][BOARD_S], int q);

void	print_board(char board[BOARD_S][BOARD_S]);

/*
 * Check if a row is free.
 *
 * return 1 if true, 0 otherwise.
 */
int		is_free_r(char board[BOARD_S][BOARD_S], int row, int col);

/*
 * Check if the diagonals are free (diagonal '\' and '/')
 *
 * return 1 if true, 0 otherwise.
 */
int		is_free_d(char board[BOARD_S][BOARD_S], int row, int col);

int	ft_n_queens_puzzle(void)
{
	char	board[BOARD_S][BOARD_S];
	int		queen_initial;
	int		row;
	int		col;

	row = 0;
	col = 0;
	queen_initial = 0;
	while (row < BOARD_S)
	{
		col = 0;
		while (col < BOARD_S)
		{
			board[row][col] = BOARD_F;
			col++;
		}
		row++;
	}
	queen_backtracking(board, queen_initial);
}

void	queen_backtracking(char board[BOARD_S][BOARD_S], int q_col)
{
	int	row;

	row = 0;
	if (q_col < BOARD_S)
	{
		while (row < BOARD_S)
		{
			if (is_free_r(board, row, q_col) && is_free_d(board, row, q_col))
			{
				board[row][q_col] = row;
				queen_backtracking(board, q_col + 1);
				board[row][q_col] = BOARD_F;
			}
			row++;
		}
	}
	else
	{
		print_board(board);
	}
}

void	print_board(char board[BOARD_S][BOARD_S])
{
	int		col;
	int		row;
	char	tmp;

	col = 0;
	row = 0;
	while (col < BOARD_S)
	{
		row = 0;
		while (row < BOARD_S)
		{
			if (board[row][col] != BOARD_F)
			{
				tmp = (board[row][col]) + '0';
				write(1, &tmp, 1);
				break ;
			}
		row++;
		}
	col++;
	}
	tmp = '\n';
	write(1, &tmp, 1);
}

int	is_free_r(char board[BOARD_S][BOARD_S], int row, int col)
{
	while (col >= 0)
	{
		if (board[row][col] != BOARD_F)
			return (0);
		col--;
	}
	return (1);
}

int	is_free_d(char board[BOARD_S][BOARD_S], int row, int col)
{
	int	tmp_col;
	int	tmp_row;

	tmp_col = col;
	tmp_row = row;
	while (tmp_row >= 0 && tmp_col >= 0)
	{
		if (board[tmp_row][tmp_col] != BOARD_F)
			return (0);
		tmp_col--;
		tmp_row--;
	}
	tmp_col = col;
	tmp_row = row;
	while (tmp_row < BOARD_S && tmp_col >= 0)
	{
		if (board[tmp_row][tmp_col] != BOARD_F)
			return (0);
		tmp_col--;
		tmp_row++;
	}
	return (1);
}
