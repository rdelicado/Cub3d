/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:42 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/18 09:19:07 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calcula la posicion y direccion del rayo
 */

void	position_direcction_ray(t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)WIDTH - 1;
	r->ray_dir_x = r->p->dir_x + r->p->plane_x * r->camera_x;
	r->ray_dir_y = r->p->dir_y + r->p->plane_y * r->camera_x;
}
/**
 * @brief Calcula la hipotenusa de los siguientes triangulos
*/

void	delta_dist(t_ray *r)
{
	if (r->ray_dir_x == 0)
		r->delta_dist_x = INFINITE;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = INFINITE;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
}

/**
* @brief Calcula la hipotenusa desde el jugador
*/

void	side_dist(t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (r->p->px - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - r->p->px) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (r->p->py - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - r->p->py) * r->delta_dist_y;
	}
}

/**
 * @brief Realiza el algoritmo DDA
 * Cuando hit = 1, se ha encontrado una pared
 * Cuando side = 0, se ha encontrado una pared en el eje X (East/West)
 * Cuando side = 1, se ha encontrado una pared en el eje Y (North/South)
 * compara las distancias de las paredes en X e Y
 * Se elige la menor distancia para evitar que el rayo atraviese
 * las paredes
 */

void	perform_dda(t_ray *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->m->d->map[r->map_x][r->map_y] != '0')
			r->hit = 1;
	}
}

/**
 * @brief Calculo de la linea perpendicular a la pared
 * Calcula la distancia perpendicular a la pared
 * Calcula la altura de la linea a dibujar
 */

void	per_wall_dist(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
	r->line_height = (int)(HEIGHT / r->perp_wall_dist);
}
