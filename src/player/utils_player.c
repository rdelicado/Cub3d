/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:49 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_ray *r, int x, int y)
{
	if (x == 1 && y == 0)
		update_position(r, r->p->dir_x, r->p->dir_y);
	else if (x == -1 && y == 0)
		update_position(r, -r->p->dir_x, -r->p->dir_y);
	else if (x == 0 && y == 1)
		update_position(r, r->p->dir_y, -r->p->dir_x);
	else if (x == 0 && y == -1)
		update_position(r, -r->p->dir_y, r->p->dir_x);
}

void	update_position(t_ray *r, double dir_x, double dir_y)
{
	if (r->m->d->map[(int)(r->p->px + dir_x \
	* r->p->move_speed)][(int)r->p->py] != '1')
		r->p->px += dir_x * r->p->move_speed;
	if (r->m->d->map[(int)r->p->px][(int)(r->p->py + dir_y \
	* r->p->move_speed)] != '1')
		r->p->py += dir_y * r->p->move_speed;
}

void	turn_player(t_ray *r, int turn)
{
	double	rotation_angle;

	rotation_angle = turn * r->p->rot_speed;
	rotate_player(r, rotation_angle);
}

void	rotate_player(t_ray *r, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_angle;
	double	sin_angle;

	old_dir_x = r->p->dir_x;
	old_plane_x = r->p->plane_x;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	r->p->dir_x = old_dir_x * cos_angle - r->p->dir_y * sin_angle;
	r->p->dir_y = old_dir_x * sin_angle + r->p->dir_y * cos_angle;
	r->p->plane_x = old_plane_x * cos_angle - r->p->plane_y * sin_angle;
	r->p->plane_y = old_plane_x * sin_angle + r->p->plane_y * cos_angle;
}
