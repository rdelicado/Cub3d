/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:31 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/19 13:10:32 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// FT_WINDOW
void	ft_window(t_map *m, t_ray *r);
void	map_color_background(t_map *map);
void	raycasting(t_ray *r);
int		get_rgba(int r, int g, int b, int a);

// RAYCAST
void	position_direcction_ray(t_ray *r, int x);
void	delta_dist(t_ray *r);
void	side_dist(t_ray *r);
void	perform_dda(t_ray *r);
void	per_wall_dist(t_ray *r);

// UTILS_RAYCAST
void	draw_start_end(t_ray *r);
void	verline(t_ray *r, int x);
void	print_lines(t_ray *r, int x);
void	player_orientation(t_map *m, t_player *p);
void	player_orientation2(t_map *m, t_player *p);

// TEXTURES
void	load_textures(t_ray *r);
void	wall_face(t_ray *r);
void	coordinate_wall_x(t_ray *r);
void	check_side(t_ray *r);
void	init_position_texture(t_ray *r);
