/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:05 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/19 13:32:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <stddef.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "main.h"
# include "parser.h"
# include "player.h"
# include "raycasting.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10
# define WIDTH 1280
# define HEIGHT 720
# define MOVE_SPEED 0.09
# define ROT_SPEED 0.06
# define INFINITE 1e30

#endif