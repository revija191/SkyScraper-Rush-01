/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlohitha <rlohitha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:03:15 by rlohitha          #+#    #+#             */
/*   Updated: 2026/09/27 14:14:28 by rlohitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_check_row_input(int r);
int	ft_check_line(int *line, int lvalue, int rvalue);
int	ft_left_visibility(int *line);
int	ft_right_visibility(int *line);
extern int	g_map[4][4];
extern int	g_views[16];

int	ft_check_row_input(int r)
{
	int	row[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		row[i] = g_map[r][i];
		i++;
	}
	return (ft_check_line(row, g_views[8 + r], g_views[12 + r]));
}

int	ft_check_line(int *line, int left_value, int right_value)
{
	int	leftvisibility;
	int	rightvisibility;

	leftvisibility = ft_left_visibility(line);
	rightvisibility = ft_right_visibility(line);
	if (leftvisibility == left_value && rightvisibility == right_value)
		return (1);
	else
		return (0);
}

int	ft_left_visibility(int *line)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_right_visibility(int *line)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	i = 3;
	count = 0;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count);
}
