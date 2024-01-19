/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:50 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/18 18:17:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_ray *r)
{
	r->texs[0] = mlx_load_png(r->m->d->path_no);
	if (!r->texs[0])
	{
		printf("Error\nNo se ha podido cargar la textura Norte\n");
		exit(0);
	}
	r->texs[1] = mlx_load_png(r->m->d->path_so);
	if (!r->texs[1])
	{
		printf("Error\nNo se ha podido cargar la textura Sur\n");
		exit(0);
	}
	r->texs[2] = mlx_load_png(r->m->d->path_we);
	if (!r->texs[2])
	{
		printf("Error\nNo se ha podido cargar la textura Oeste\n");
		exit(0);
	}
	r->texs[3] = mlx_load_png(r->m->d->path_ea);
	if (!r->texs[3])
	{
		printf("Error\nNo se ha podido cargar la textura Este\n");
		exit(0);
	}
}

/**
 * @brief Calcular la coordenada de la textura
 *Si side = 0, ha colisionado con una pared en el eje x, direccion norte o sur
 *Si side = 1, ha colisionado con una pared en el eje y, direccion este u oeste
 */

void	coordinate_wall_x(t_ray *r)
{
	if (r->side == 0)
		r->wall_x = r->p->py + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = r->p->px + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
}

/**
 * @brief Ajusta la posicion de la textura
 */

void	check_side(t_ray *r)
{
	r->tx = (int)(r->wall_x * (float)r->texs[r->side]->width);
	r->tx = r->texs[r->side]->width - r->tx - 1;
}

/**
 * @brief Verifica en que lado ha colisionado con la pared
 * Si tex_num = 0, ha colisionado con una pared en el eje x, direccion norte
 * Si tex_num = 1, ha colisionado con una pared en el eje y, direccion sur
 * Si tex_num = 2, ha colisionado con una pared en el eje x, direccion oeste
 * Si tex_num = 3, ha colisionado con una pared en el eje x, direccion este
 */

void	wall_face(t_ray *r)
{
	if (r->side == 0 && (r->map_x - r->p->px) >= 0)
		r->side += 2;
	if (r->side == 1 && (r->map_y - r->p->py) >= 0)
		r->side += 2;
}

/**
 * @brief Calcula la posicion de la textura
 * tpos = posicion de la textura
 * step = cuanto se incrementa la textura en el eje y
 */

void	init_position_texture(t_ray *r)
{
	r->step = 1.0 * r->texs[r->side]->height / r->line_height;
	r->tpos = (r->draw_start - HEIGHT / 2 + r->line_height / 2) * r->step;
}
