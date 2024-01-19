/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   120errorMessages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:07 by pespinos          #+#    #+#             */
/*   Updated: 2024/01/17 16:58:08 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_messages(int message)
{
	printf("\nERROR\n");
	if (message == 1)
		printf("EN LA COMPROBACION PREVIA DEL FICHERO\n\n");
	else if (message == 2)
		printf("SE HAN ENCONTRADO CARACTERES INVALIDOS EN EL MAPA\n\n");
	else if (message == 3)
		printf("MUROS NO CERRADOS\n\n");
	else if (message == 4)
		printf("NO HAY JUGADOR\n\n");
	else if (message == 5)
		printf("LINEA VACIA EN EL MAPA\n\n");
	else if (message == 6)
		printf("CARACTERES FUERA DE LOS MUROS\n\n");
	else if (message == 7)
		printf("CONTENIDO DEL ARCHIVO ERRONEO\n\n");
	else if (message == 8)
		printf("PROBLEMA AL RESERVAR MEMORIA\n\n");
	else if (message == 9)
		printf("NO EXISTE JUGADOR EN EL MAPA");
	else if (message == 10)
		printf("ERROR EN LOS LIMITES RGB\n\n");
	exit(1);
}
