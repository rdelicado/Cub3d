/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   102-3checkContentFile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:02 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/19 16:46:07 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_start_row(char *row_n_content, t_data *d)
{
	char	**content_without_space;

	if (!row_n_content)
		ft_error_messages(7);
	content_without_space = ft_split(row_n_content, ' ');
	if (content_without_space[2])
		ft_error_messages(7);
	ft_check_init_row(content_without_space[0], content_without_space[1], d);
	ft_free_matrix(content_without_space);
}

void	ft_add_row_list(t_data *d, char *str)
{
	if (!d->found_map)
		d->found_map = 1;
	ft_lstadd_back(&d->row_list, ft_lstnew(str));
}

int	ft_check_data_file(t_data *d)
{
	int	r;

	r = 0;
	while (d->all_content_n[r])
	{
		if (d->found_no && d->found_so && d->found_ea && d->found_we
			&& d->found_f && d->found_c)
		{
			d->number_rows++;
			ft_add_row_list(d, d->all_content_n[r]);
		}
		else
			ft_check_start_row(d->all_content_n[r], d);
		r++;
	}
	if (d->found_no == 1 && d->found_so == 1 && d->found_ea == 1
		&& d->found_we == 1 && d->found_f == 1 && d->found_c == 1
		&& d->found_map == 1)
		return (1);
	else
	{
		ft_error_messages(7);
		return (0);
	}
}

char	**ft_create_map(t_data *d)
{
	char	**matrix;
	int		r;
	t_list	*tmp;

	tmp = d->row_list;
	r = 0;
	matrix = malloc(d->number_rows * sizeof(char *));
	if (!matrix)
		ft_error_messages(8);
	while (r < d->number_rows)
	{
		matrix[r] = NULL;
		matrix[r] = ft_strdup(tmp->content);
		tmp = tmp->next;
		r++;
	}
	return (matrix);
}

void	ft_check_content_file(t_data *d)
{
	d->all_content = ft_get_all_content(d);
	d->all_content_n = ft_split(d->all_content, '\n');
	ft_check_data_file(d);
	d->map = ft_create_map(d);
	ft_check_characters(d);
}
