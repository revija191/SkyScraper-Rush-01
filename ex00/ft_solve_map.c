/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlohitha <rlohitha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:03:18 by rlohitha          #+#    #+#             */
/*   Updated: 2026/09/27 14:14:23 by rlohitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_fill_number(int square, int n);
int	ft_validate_num(int r, int c, int n);
int	ft_check_row_input(int r);
int	ft_check_col(int c);
int	ft_check_line(int *line, int left_value, int right_value);
extern int	g_map[4][4];
extern int	g_views[16];

int	ft_solve_map(int square)
{
	int	c;
	int	n;

	if (square == 16)
	{
		c = 0;
		while (c < 4)
		{
			if (!ft_check_col(c))
			{
				return (0);
			}
			c++;
		}
		return (1);
	}
	n = 1;
	while (n <= 4)
	{
		if (ft_fill_number(square, n))
			return (1);
		n++;
	}
	return (0);
}

int	ft_fill_number(int square, int n)
{
	int	r;
	int	c;

	r = square / 4;
	c = square % 4;
	if (!ft_validate_num(r, c, n))
		return (0);
	g_map[r][c] = n;
	if (c == 3 && !ft_check_row_input(r))
	{
		g_map[r][c] = 0;
		return (0);
	}
	if (ft_solve_map(square + 1))
	{
		return (1);
	}
	g_map[r][c] = 0;
	return (0);
}

int	ft_validate_num(int r, int c, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_map[r][i] == n || g_map[i][c] == n)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_col(int c)
{
	int	col[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		col[i] = g_map[i][c];
		i++;
	}
	return (ft_check_line(col, g_views[c], g_views[c + 4]));
}
