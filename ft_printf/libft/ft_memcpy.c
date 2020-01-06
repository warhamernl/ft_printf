/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:39:28 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/07 14:00:17 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*adest;
	unsigned char	*bsrc;
	size_t			i;

	adest = (unsigned char *)dest;
	bsrc = (unsigned char *)src;
	i = 0;
	while (i < count)
	{
		adest[i] = bsrc[i];
		i++;
	}
	return (dest);
}
