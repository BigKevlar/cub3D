/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:16:08 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/21 18:33:47 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	*angle_to_vector(double angle)
{
	int vector[2];

	vector[0] = cos(angle);
	vector[1] = sin(angle);
	return (vector);
}

double	vector_to_angle(int x, int y)
{
	return (atan(y / x));
}