/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlohitha <rlohitha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:03:22 by rlohitha          #+#    #+#             */
/*   Updated: 2026/09/27 14:55:42 by rlohitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	g_map[4][4];
int	g_views[16];
int		ft_check_input(char *str);
int		ft_solve_map(int c);
void	ft_print_map(void);

int	ft_check_input(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		g_views[j] = str[i] - 48;
		j++;
		if (i != 30)
		{
			i++;
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print_map(void)
{
	int		r;
	int		c;
	char	mapval;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (c > 0)
				write (1, " ", 1);
			mapval = g_map[r][c] + 48;
			write (1, &mapval, 1);
			c++;
		}
		r++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "Error\n", 7);
		return (1);
	}
	if (!ft_check_input(argv[1]))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (ft_solve_map(0))
		ft_print_map();
	else
		write(1, "Error\n", 7);
	return (0);
}
