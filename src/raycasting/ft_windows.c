/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:29 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:30 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_window(t_map *m, t_ray *r)
{
	map_color_background(m);
	player_orientation(r->m, r->p);
	m->d->map[(int)r->p->px][(int)r->p->py] = '0';
	load_textures(r);
	raycasting(r);
}

void	raycasting(t_ray *r)
{
	int	x;

	x = 0;
	r->wall = mlx_new_image(r->m->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(r->m->mlx, r->wall, 0, 0) == -1)
		ft_error_messages(5);
	while (x < WIDTH)
	{
		position_direcction_ray(r, x);
		r->map_x = (int)r->p->px;
		r->map_y = (int)r->p->py;
		delta_dist(r);
		side_dist(r);
		perform_dda(r);
		per_wall_dist(r);
		draw_start_end(r);
		verline(r, x);
		x++;
	}
}

void	map_color_background(t_map *map)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	map->sky_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->floor_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(map->sky_image, x, y, map->sky_color);
			else if (y >= HEIGHT / 2)
				mlx_put_pixel(map->floor_image, x, HEIGHT - y,
					map->floor_color);
		}
	}
	if (mlx_image_to_window(map->mlx, map->sky_image, 0, 0) == -1)
		ft_error_messages(5);
	if (mlx_image_to_window(map->mlx, map->floor_image, 0, HEIGHT / 2) == -1)
		ft_error_messages(5);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
