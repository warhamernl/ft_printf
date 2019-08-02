/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:29:58 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 17:02:08 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *a;

	a = (void *)malloc(sizeof(unsigned char) * size);
	if (!a)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
