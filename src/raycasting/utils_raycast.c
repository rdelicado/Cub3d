/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:40:00 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/18 09:05:39 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calcular el pixel mas alto y mas bajo para dibujar la pared
 */

void	draw_start_end(t_ray *r)
{
	r->draw_start = ((-1) * r->line_height) / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + HEIGHT / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
}

/**
 * @brief Dibujar los pixeles de la pared
 */

void	verline(t_ray *r, int x)
{
	coordinate_wall_x(r);
	check_side(r);
	wall_face(r);
	init_position_texture(r);
	print_lines(r, x);
}

/**
 * @brief Calcular la posicion de la textura
 * 1. Calcula la posicion vertical @param ty de la pared
 * 2. Calcula el siguiente paso de la textura @param tpos para la pared
 * 3. Obtiene el color de la textura @param p
 * 4. Convierte el color de la textura a un color de 32 bits @param color
 * 5. Dibuja la linea de pixeles
 */

void	print_lines(t_ray *r, int x)
{
	int			y;
	uint8_t		*p;
	uint32_t	color;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->ty = (int)r->tpos;
		r->tpos += r->step;
		p = &r->texs[r->side]->pixels[r->texs[r->side]->width * r->ty * 4
			+ r->tx * 4];
		color = (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
		mlx_put_pixel(r->wall, x, y, color);
		y++;
	}
}

/**
 * @brief Calcular la direccion de la camara
 */

void	player_orientation(t_map *m, t_player *p)
{
	if (m->d->player_orientation == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (m->d->player_orientation == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
	else if (m->d->player_orientation == 'E' || m->d->player_orientation == 'W')
		player_orientation2(m, p);
}

void	player_orientation2(t_map *m, t_player *p)
{
	if (m->d->player_orientation == 'E')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (m->d->player_orientation == 'W')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}
