/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:03:39 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/17 16:52:27 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	d;
	t_map	m;

	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	init_structs(&d, &m);
	start_game(&m);
	ft_free_all(&d);
	return (0);
}

int32_t	start_game(t_map *m)
{
	t_player	p;
	t_ray		r;

	init_struct_player(m, &p);
	init_struct_ray(m, m->p, &r);
	m->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!m->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(m->mlx, m->title);
	ft_window(m, &r);
	mlx_key_hook(m->mlx, &key_hook, &r);
	mlx_loop_hook(m->mlx, &exit_hook, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}

void	exit_hook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		exit(0);
}
