/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:18:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/17 17:22:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h" /* Libreria 42 "jmartos-". */

/*#A cada carácter de la cadena "s" se aplica la función "f", dando como
parámetros el índice de cada carácter dentro de "s" y la dirección
del propio carácter, que podrá modificarse si es necesario.#*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cont;

	cont = 0;
	while (s[cont])
	{
		f(cont, s + cont);
		cont++;
	}
}
/*Similar a ft_strmapi pero sin reservar memoria y sin devolver nada???*/

/*(...main en desarrollo...)*/