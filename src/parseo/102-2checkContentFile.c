/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   102-2checkContentFile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:59 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/19 16:42:03 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_init_row1(char *c_w_space, char *path, t_data *d)
{
	if (!ft_strncmp(c_w_space, "NO", 2) && d->found_no == 0
		&& ft_strlen(c_w_space) == 2)
	{
		d->found_no = 1;
		if (path)
			d->path_no = ft_strdup(path);
		else
			ft_error_messages(7);
	}
	else if (!ft_strncmp(c_w_space, "NO", 2))
		ft_error_messages(7);
	else if (!ft_strncmp(c_w_space, "SO", 2) && d->found_so == 0
		&& ft_strlen(c_w_space) == 2)
	{
		d->found_so = 1;
		if (path)
			d->path_so = ft_strdup(path);
		else
			ft_error_messages(7);
	}
	else if (!ft_strncmp(c_w_space, "SO", 2))
		ft_error_messages(7);
}

void	ft_check_init_row2(char *c_w_space, char *path, t_data *d)
{
	if (!ft_strncmp(c_w_space, "EA", 2) && d->found_ea == 0
		&& ft_strlen(c_w_space) == 2)
	{
		d->found_ea = 1;
		if (path)
			d->path_ea = ft_strdup(path);
		else
			ft_error_messages(7);
	}
	else if (!ft_strncmp(c_w_space, "EA", 2))
		ft_error_messages(7);
	else if (!ft_strncmp(c_w_space, "WE", 2) && d->found_we == 0
		&& ft_strlen(c_w_space) == 2)
	{
		d->found_we = 1;
		if (path)
			d->path_we = ft_strdup(path);
		else
			ft_error_messages(7);
	}
	else if (!ft_strncmp(c_w_space, "WE", 2))
		ft_error_messages(7);
}

void	ft_check_init_row3(char *c_w_space, char *path, t_data *d)
{
	char	**rgb;

	if (!ft_strncmp(c_w_space, "F", 1) && d->found_f == 0)
	{
		d->found_f = 1;
		rgb = ft_split(path, ',');
		if (!rgb[0] || !rgb[1] || !rgb[2])
			ft_error_messages(7);
		if (ft_o_num(rgb[0]) && ft_o_num(rgb[1]) && ft_o_num(rgb[2]))
		{
			d->f_r = ft_atoi(rgb[0]);
			d->f_g = ft_atoi(rgb[1]);
			d->f_b = ft_atoi(rgb[2]);
		}
		ft_free_matrix(rgb);
		if (d->f_r < 0 || d->f_r > 255 || d->f_g < 0 || d->f_g > 255
			|| d->f_b < 0 || d->f_b > 255)
			ft_error_messages(10);
	}
	else if (!ft_strncmp(c_w_space, "F", 1))
		ft_error_messages(7);
}

void	ft_check_init_row4(char *c_w_space, char *path, t_data *d)
{
	char	**rgb;

	if (!ft_strncmp(c_w_space, "C", 1) && d->found_c == 0)
	{
		d->found_c = 1;
		rgb = ft_split(path, ',');
		if (!rgb[0] || !rgb[1] || !rgb[2])
			ft_error_messages(7);
		if (ft_o_num(rgb[0]) && ft_o_num(rgb[1]) && ft_o_num(rgb[2]))
		{
			d->c_r = ft_atoi(rgb[0]);
			d->c_g = ft_atoi(rgb[1]);
			d->c_b = ft_atoi(rgb[2]);
		}
		ft_free_matrix(rgb);
		if (d->c_r < 0 || d->c_r > 255 || d->c_g < 0 || d->c_g > 255
			|| d->c_b < 0 || d->c_b > 255)
			ft_error_messages(10);
	}
	else if (!ft_strncmp(c_w_space, "C", 1))
		ft_error_messages(7);
}

//c_w_space -> content without space
void	ft_check_init_row(char *c_w_space, char *path, t_data *d)
{
	if (!ft_strncmp(c_w_space, "NO", 2) || !ft_strncmp(c_w_space, "SO", 2)
		|| !ft_strncmp(c_w_space, "EA", 2) || !ft_strncmp(c_w_space, "WE", 2))
	{
		ft_check_init_row1(c_w_space, path, d);
		ft_check_init_row2(c_w_space, path, d);
	}
	else if (!ft_strncmp(c_w_space, "F", 1)
		|| !ft_strncmp(c_w_space, "C", 1))
	{
		ft_check_init_row3(c_w_space, path, d);
		ft_check_init_row4(c_w_space, path, d);
	}
	else
		ft_error_messages(7);
}
