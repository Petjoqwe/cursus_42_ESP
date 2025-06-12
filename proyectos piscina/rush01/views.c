/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:09:21 by paguiler          #+#    #+#             */
/*   Updated: 2025/02/08 19:12:47 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_visibility(char **puzzle_board, int start, int end, int step, int fixed)
{
	int		i;
	char	visible;
	char	highest;

	i = start;
	visible = '1';
	highest = puzzle_board[fixed][i];
	while (i != end)
	{
		if (puzzle_board[fixed][i] > highest)
		{
			highest = puzzle_board[fixed][i];
			visible++;
		}
		i += step;
	}
	return (visible);
}

int	is_correct_view(char **puzzle_board, int index, int is_row, int is_left_or_top)
{
	int	visible;

	if (is_left_or_top)
		visible = check_visibility(puzzle_board, 1, 5, 1, index);
	else
		visible = check_visibility(puzzle_board, 4, 0, -1, index);

	if (is_left_or_top)
		return (puzzle_board[index][0] == visible);
	else
		return (puzzle_board[index][5] == visible);
}

int	is_in_row(char **puzzle_board, int row, int column, int digit)
{
	int	i;

	i = 1;
	while (i < column)
	{
		if (puzzle_board[row][i] == digit + '0')
			return (1);
		i++;
	}
	return (0);
}

int	is_in_column(char **puzzle_board, int row, int column, int digit)
{
	int	i;

	i = 1;
	while (i < row)
	{
		if (puzzle_board[i][column] == digit + '0')
			return (1);
		i++;
	}
	return (0);
}