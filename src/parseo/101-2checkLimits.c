/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   101-2checkLimits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:50 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:57:51 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_around(t_data *d, int x, int y)
{
	if (!d->map_flood_fill[x - 1][y] || !d->map_flood_fill[x + 1][y]
			|| !d->map_flood_fill[x][y - 1] || !d->map_flood_fill[x][y + 1]
			|| y > ft_strlen(d->map_flood_fill[x - 1])
			|| y > ft_strlen(d->map_flood_fill[x + 1]))
	{
		return (0);
	}
	return (1);
}

int	ft_check_outer_walls(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < d->number_rows)
	{
		y = 0;
		while (d->map_flood_fill[x][y])
		{
			if ((x == 0 || x == d->number_rows - 1))
				if (d->map_flood_fill[x][y] == '#')
					return (0);
			if ((y == 0 || !d->map_flood_fill[x][y + 1]))
				if (d->map_flood_fill[x][y] == '#')
					return (0);
			if (d->map_flood_fill[x][y] == '#')
				if (!ft_check_around(d, x, y))
					return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_compare_maps(t_data *d)
{
	if (!ft_check_inner_walls(d))
		ft_error_messages(3);
	if (!ft_check_outer_walls(d))
		ft_error_messages(3);
}

void	ft_fill_islands(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < d->number_rows)
	{
		y = 0;
		while (d->map_flood_fill[x][y])
		{
			if (d->map_flood_fill[x][y] != '1'
					&& d->map_flood_fill[x][y] != ' ')
			{
				ft_flood_fill(x, y, d);
			}
			y++;
		}
		x++;
	}
}
