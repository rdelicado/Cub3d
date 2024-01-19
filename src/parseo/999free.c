/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   999free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:16 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:58:17 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_list(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free (tmp);
		tmp = next;
	}
}

void	ft_free_matrix(char **matrix)
{
	int	x;

	x = 0;
	while (matrix[x])
	{
		free (matrix[x]);
		x++;
	}
	free (matrix);
}

void	ft_free_all(t_data *d)
{
	int	r;

	r = 0;
	while (r < d->number_rows)
	{
		if (d->map[r])
			free(d->map[r]);
		if (d->map_flood_fill[r])
			free(d->map_flood_fill[r]);
		r++;
	}
	if (d->map)
		free (d->map);
	if (d->map_flood_fill)
		free (d->map_flood_fill);
	ft_free_matrix(d->all_content_n);
	ft_free_list(d->row_list);
	free (d->path_no);
	free (d->path_so);
	free (d->path_ea);
	free (d->path_we);
	free(d->all_content);
}
