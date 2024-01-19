/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:36 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/17 14:35:37 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_ray	*r;

	r = (t_ray *)param;
	(void)keydata;
	mlx_delete_image(r->m->mlx, r->wall);
	move_player_map(r);
	raycasting(r);
}

void	move_player_map(t_ray *r)
{
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_W))
		move_player(r, 1, 0);
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_S))
		move_player(r, -1, 0);
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_D))
		move_player(r, 0, 1);
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_A))
		move_player(r, 0, -1);
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_LEFT))
		turn_player(r, 1);
	if (mlx_is_key_down(r->m->mlx, MLX_KEY_RIGHT))
		turn_player(r, -1);
}
