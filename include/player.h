/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:24 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/19 13:10:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// MOVE_PLAYER
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player_map(t_ray *r);

// UTILS_PLAYER
void	move_player(t_ray *r, int x, int y);
void	update_position(t_ray *r, double dir_x, double dir_y);
void	turn_player(t_ray *r, int turn);
void	rotate_player(t_ray *r, double angle);