/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   102-1checkContentFile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:57 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/19 15:54:50 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_my_strjoin_operations(t_my_strjoin_data *d)
{
	while (d->s1[d->p])
	{
		d->str[d->p] = d->s1[d->p];
		d->p++;
	}
	while (d->s2[d->q])
	{
		d->str[d->p + d->q] = d->s2[d->q];
		d->q++;
	}
	d->str[d->p + d->q] = '\n';
	d->str[d->p + d->q + 1] = '\0';
}

char	*ft_my_strjoin(char **str1, char **str2)
{
	t_my_strjoin_data	d;

	if (*str1)
	{
		d.p = 0;
		d.q = 0;
		d.str = malloc ((ft_strlen(*str1) + ft_strlen(*str2) + 2)
				* sizeof (d.str));
		if (!d.str)
		{
			free (d.str);
			return (NULL);
		}
		d.s1 = ft_strdup(*str1);
		d.s2 = ft_strdup(*str2);
		ft_my_strjoin_operations(&d);
		free (d.s1);
		free (d.s2);
		if (*str1)
			free (*str1);
		return (d.str);
	}
	else
		return (ft_strdup(*str2));
}

char	*ft_get_all_content(t_data *d)
{
	char	*all_str;
	char	*new_str;
	int		r;

	d->fd = open(d->argv[1], O_RDONLY);
	if (d->fd == -1)
		ft_error_messages(1);
	new_str = ft_get_next_line(d->fd);
	r = 0;
	while (new_str)
	{
		if (r == 0)
			all_str = NULL;
		all_str = ft_my_strjoin(&all_str, &new_str);
		free (new_str);
		new_str = ft_get_next_line(d->fd);
		r++;
	}
	return (all_str);
}
