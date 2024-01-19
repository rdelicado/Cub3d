/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:02:54 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/17 14:06:13 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 ** @brief Inicializa las estructuras
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 */

void	init_structs(t_data *d, t_map *m)
{
	m->d = d;
	init_struct_data(d);
	init_struct_map(m);
}

/**
 ** @brief Inicializa la estructura de los datos
 * @param d Estructura de los datos
 * @param flag_char Flag para saber si hay un caracter no permitido
 * @param number_rows Numero de filas del mapa
 * @param x_position_player Posicion del jugador en el eje x
 * @param y_position_player Posicion del jugador en el eje y
 * @param map Mapa
 * @param player_orientation Orientacion del jugador
 * @param found_no Flag para saber si se ha encontrado la textura norte
 * @param path_no Path de la textura norte
 * @param found_so Flag para saber si se ha encontrado la textura sur
 * @param path_so Path de la textura sur
 * @param found_we Flag para saber si se ha encontrado la textura oeste
 * @param path_we Path de la textura oeste
 * @param found_ea Flag para saber si se ha encontrado la textura este
 * @param path_ea Path de la textura este
 * @param found_f Flag para saber si se ha encontrado el color del suelo
 * @param path_f Path del color del suelo
 * @param found_c Flag para saber si se ha encontrado el color del cielo
 * @param path_c Path del color del cielo
 * @param found_map Flag para saber si se ha encontrado el mapa
 * @param row_list Lista de filas
 */

void	init_struct_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	d->player_orientation = '\0';
	d->found_no = 0;
	d->path_no = NULL;
	d->found_so = 0;
	d->path_so = NULL;
	d->found_we = 0;
	d->path_we = NULL;
	d->found_ea = 0;
	d->path_ea = NULL;
	d->found_f = 0;
	d->path_f = NULL;
	d->found_c = 0;
	d->path_c = NULL;
	d->found_map = 0;
	d->row_list = NULL;
	ft_check_limits(d);
}

/**
 ** @brief Inicializa la estructura del mapa
 * @param m Estructura del mapa
 * @param mlx Estructura de mlx
 * @param mini Esructura minimapa
 * @param mi_bg Estructura minimapa background
 * @param title Titulo de la ventana
 * @param sky_image Imagen del cielo
 * @param floor_image Imagen del suelo
 * @param sky_color Color del cielo
 * @param floor_color Color del suelo
 * @param start_x Posicion de inicio en el eje x
 * @param start_y Posicion de inicio en el eje y
 * @param show_map Si se muestra el mapa
 * @param prev_m_key_state Si se ha pulsado la tecla m
 * @param block_center_x Centro del bloque en el eje x
 * @param block_center_y Centro del bloque en el eje y
 * @param player_x Posicion del jugador en el eje x
 * @param player_y Posicion del jugador en el eje y
 * @param dx Ancho del bloque
 * @param dy Alto del bloque
 * @param map_x Posicion del jugador en el mapa en el eje x
 * @param map_y Posicion del jugador en el mapa en el eje y
 */

void	init_struct_map(t_map *m)
{
	m->mlx = NULL;
	m->mini = NULL;
	m->mi_bg = NULL;
	m->map = NULL;
	m->clear = NULL;
	m->title = "cub3d";
	m->sky_image = NULL;
	m->floor_image = NULL;
	m->sky_color = get_rgba(m->d->c_r, m->d->c_g, m->d->c_b, 255);
	m->floor_color = get_rgba(m->d->f_r, m->d->f_g, m->d->f_b, 255);
	m->start_x = 0;
	m->start_y = 0;
	m->show_map = false;
	m->dx = 5;
	m->dy = 5;
	m->block_center_x = 0;
	m->block_center_y = 0;
	m->player_x = 0;
	m->player_y = 0;
	m->map_x = 0;
	m->map_y = 0;
}

/**
 ** @brief Inicializa la estructura del jugador
 * @param p Estructura del jugador
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 * @param px Posicion del jugador en el eje x
 * @param py Posicion del jugador en el eje y
 * @param dir_x Direccion del jugador en el eje x
 * @param dir_y Direccion del jugador en el eje y
 * @param old_dir_x Direccion anterior del jugador en el eje x
 * @param old_dir_y Direccion anterior del jugador en el eje y
 * @param plane_x Plano de la camara en el eje x
 * @param plane_y Plano de la camara en el eje y
 * @param old_plane_x Plano anterior de la camara en el eje x
 * @param old_plane_y Plano anterior de la camara en el eje y
 * @param move_speed Velocidad de movimiento en pixeles
 * @param rot_speed Velocidad de rotacion en radianes
 * @param move Si se esta moviendo, 0 = no se mueve, 1 = adelante y -1 = atras
 * @param turn Si se esta girando, 0 = no se mueve, 1 = derecha y -1 = izquierda
 * @param angle_rot Angulo de rotacion
 */

void	init_struct_player(t_map *m, t_player *p)
{
	m->p = p;
	p->m = m;
	p->d = m->d;
	p->px = p->d->x_position_player + 0.5;
	p->py = p->d->y_position_player + 0.5;
	p->dir_x = 0;
	p->dir_y = 0;
	p->old_dir_x = 0;
	p->old_dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0;
	p->old_plane_x = 0;
	p->old_plane_y = 0;
	p->move_speed = MOVE_SPEED;
	p->rot_speed = ROT_SPEED;
	p->angle_rot = 0;
	p->move = 0;
	p->turn = 0;
}

/**
 ** @brief Estructura del raycasting
 * @param camera_x Posicion de la camara en el eje x
 * @param ray_dir_x Direccion del rayo en el eje x
 * @param ray_dir_y Direccion del rayo en el eje y
 * @param map_x Posicion del rayo en el mapa en el eje x
 * @param map_y Posicion del rayo en el mapa en el eje y
 * @param side_dist_x Distancia del rayo en el eje x
 * @param side_dist_y Distancia del rayo en el eje y
 * @param delta_dist_x Distancia del rayo en el eje x
 * @param delta_dist_y Distancia del rayo en el eje y
 * @param perp_wall_dist Distancia de la pared perpendicular
 * @param step_x Paso del rayo en el eje x
 * @param step_y Paso del rayo en el eje y
 * @param hit Si el rayo ha chocado con una pared
 * @param side Si el rayo ha chocado con una pared en el eje x o en el eje y
 * @param line_height Altura de la linea que se va a pintar
 * @param draw_start Donde empieza a pintar la linea
 * @param draw_end Donde termina de pintar la linea
 * @param wall_x Posicion de la pared en el eje x
 * @param text_ea Textura este
 * @param text_no Textura norte
 * @param text_so Textura sur
 * @param text_we Textura oeste
 * @param text_ea_t Textura este en formato mlx_texture_t
 * @param text_no_t Textura norte en formato mlx_texture_t
 * @param text_so_t Textura sur en formato mlx_texture_t
 * @param text_we_t Textura oeste en formato mlx_texture_t
 * @param tx Posicion de la textura en el eje x
 * @param ty Posicion de la textura en el eje y
 * @param tpos Posicion de la textura
 * @param step Paso de la textura
 * @param color Color de la textura
 */

void	init_struct_ray(t_map *m, t_player *p, t_ray *r)
{
	r->p = p;
	r->m = m;
	r->wall = NULL;
	r->camera_x = 0;
	r->ray_dir_x = 0;
	r->ray_dir_y = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->side_dist_x = 0;
	r->side_dist_y = 0;
	r->delta_dist_x = 0;
	r->delta_dist_y = 0;
	r->perp_wall_dist = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->hit = 0;
	r->side = 0;
	r->line_height = 0;
	r->draw_start = 0;
	r->draw_end = 0;
	r->wall_x = 0;
	r->tx = 0;
	r->ty = 0;
	r->tpos = 0;
	r->step = 0;
}
