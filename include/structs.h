/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:35 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/19 13:10:36 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;

typedef struct s_split_data
{
	char					**result;
	int						p;
	int						w;
	int						start;
}							t_split_data;

typedef struct s_list
{
	struct s_list			*next;
	char					*content;
}							t_list;

typedef struct s_atoi_data
{
	int						result;
	int						sign;
	int						s;
}							t_atoi_data;

typedef struct s_my_strjoin_data
{
	char					*str;
	char					*s1;
	char					*s2;
	int						p;
	int						q;
}							t_my_strjoin_data;

typedef struct s_data
{
	int						argc;
	char					**argv;
	char					**map;
	char					**map_flood_fill;
	char					**all_content_n;
	char					*all_content;
	int						number_rows;
	int						number_columns;
	int						fd;
	int						flag_char;
	int						x_position_player;
	int						y_position_player;
	char					player_orientation;
	int						found_no;
	char					*path_no;
	int						found_so;
	char					*path_so;
	int						found_we;
	char					*path_we;
	int						found_ea;
	char					*path_ea;
	int						found_f;
	char					*path_f;
	int						found_c;
	char					*path_c;
	int						found_map;
	int						f_r;
	int						f_g;
	int						f_b;
	int						c_r;
	int						c_g;
	int						c_b;
	t_list					*row_list;
}							t_data;

typedef struct s_map
{
	t_data					*d;
	t_player				*p;
	mlx_t					*mlx;
	mlx_image_t				*mini;
	mlx_image_t				*sky_image;
	mlx_image_t				*floor_image;
	mlx_image_t				*mi_bg;
	mlx_image_t				*map;
	mlx_image_t				*player;
	mlx_image_t				*clear;
	uint32_t				sky_color;
	uint32_t				floor_color;
	bool					show_map;
	const char				*title;
	float					block_center_x;
	float					block_center_y;
	float					player_x;
	float					player_y;
	int						dy;
	int						dx;
	int						block_player;
	int						block_floor;
	int						block_wall;
	int						start_x;
	int						start_y;
	int						map_x;
	int						map_y;
}							t_map;

typedef struct s_player
{
	t_map					*m;
	t_data					*d;
	float					px;
	float					py;
	float					dir_x;
	float					dir_y;
	float					old_dir_x;
	float					old_dir_y;
	float					plane_x;
	float					plane_y;
	float					old_plane_x;
	float					old_plane_y;
	float					move_speed;
	float					rot_speed;
	float					angle_rot;
	int						move;
	int						turn;
}							t_player;

typedef struct s_ray
{
	t_player				*p;
	t_map					*m;
	mlx_image_t				*wall;
	float					camera_x;
	float					ray_dir_x;
	float					ray_dir_y;
	float					side_dist_x;
	float					side_dist_y;
	float					delta_dist_x;
	float					delta_dist_y;
	float					perp_wall_dist;
	float					wall_x;
	int						map_x;
	int						map_y;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						columns;
	int						tx;
	int						ty;
	float					step;
	float					tpos;
	mlx_texture_t			*texs[4];
}							t_ray;