/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:43 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:57:44 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_parameters(t_data *d)
{
	if (d->argc == 2 && ft_strnstr(d->argv[1], ".cub", ft_strlen(d->argv[1])))
		return (1);
	else
	{
		ft_error_messages(1);
		return (-1);
	}
}

int	ft_allow_chars(char *s, t_data *d)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (d->flag_char == 0)
		{
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
				d->flag_char = 1;
			else if (s[i] != '0' && s[i] != '1' && s[i] != 32)
				return (0);
		}
		else
		{
			if (s[i] != '0' && s[i] != '1' && s[i] != 32)
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_characters(t_data *d)
{
	int		r;

	r = 0;
	while (r < d->number_rows)
	{
		if (!ft_allow_chars(d->map[r], d))
			ft_error_messages(2);
		r++;
	}
	if (d->flag_char == 0)
		ft_error_messages(4);
	close(d->fd);
}
