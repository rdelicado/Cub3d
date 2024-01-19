/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000libft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:57:34 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:57:35 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strnstr(char *b, char *l, size_t len)
{
	size_t	p1;
	size_t	p2;

	p1 = 0;
	if (!*l)
		return (b);
	while (b[p1] && p1 < len)
	{
		p2 = 0;
		while (b[p1 + p2] && b[p1 + p2] == l[p2] && p1 + p2 < len)
		{
			if (l[p2 + 1] == '\0' && b[p1 + p2 + 1] == '\0')
				return (&b[p1]);
			p2++;
		}
		p1++;
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		pos;

	pos = 0;
	str = NULL;
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (str)
	{
		while (src[pos])
		{
			str[pos] = src[pos];
			pos++;
		}
		str[pos] = '\0';
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_strncmp(const char *lsh, const char *rhs, int count)
{
	int	p;
	int	control;

	p = 0;
	control = 1;
	while (p < count && control == 1)
	{
		if (lsh[p] != rhs[p])
			return ((unsigned char)lsh[p] - (unsigned char)rhs[p]);
		if (lsh[p] == '\0')
			control = 0;
		p++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	t_atoi_data	data;

	data.result = 0;
	data.sign = 1;
	data.s = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
	{
		data.s++;
		str++;
	}
	if (*str == '-' && data.s == 0)
	{
		data.sign = -1;
		str++;
	}
	if (*str == '-' && data.s == 1)
		data.sign = 0;
	while (*str >= '0' && *str <= '9')
	{
		data.result = data.result * 10 + (*str - 48);
		str++;
	}
	return (data.result * data.sign);
}
