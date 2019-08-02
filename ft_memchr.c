/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 14:43:53 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 16:52:10 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*ptra;
	unsigned char	chb;
	size_t			i;

	ptra = (unsigned char *)ptr;
	chb = (unsigned char)ch;
	i = 0;
	if (count == 0)
		return (NULL);
	while (i < count - 1)
	{
		if (ptra[i] == chb)
			return ((void *)&ptra[i]);
		i++;
	}
	if (ptra[i] == chb)
		return ((void *)&ptra[i]);
	return (NULL);
}
