/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:49:29 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 19:15:17 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(sizeof(char) * size + 1);
	if (!a)
		return (NULL);
	ft_bzero(a, size + 1);
	return (a);
}
