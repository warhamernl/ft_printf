/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:49:29 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/03 01:17:56 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * size + 1);
	if (!a)
		return (NULL);
	ft_bzero(a, size + 1);
	return (a);
}
