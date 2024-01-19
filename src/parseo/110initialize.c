/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:05 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:58:06 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_number_rows(t_data *d)
{
	int		rows;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	rows = 0;
	str = ft_get_next_line(d->fd);
	while (str != NULL)
	{
		rows++;
		free (str);
		str = ft_get_next_line(d->fd);
	}
	free (str);
	d->number_rows = rows;
	close(d->fd);
}

void	ft_initialize_map(t_data *d, char **map)
{
	int	r;

	r = 0;
	while (r < d->number_rows)
	{
		map[r] = NULL;
		r++;
	}
}
