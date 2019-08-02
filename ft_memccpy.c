/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:45:32 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 21:13:40 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;
	size_t			i;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ucdst[i] = ucsrc[i];
		if (ucsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
