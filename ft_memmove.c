/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:47:44 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 16:50:47 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*desta;
	unsigned char	*srcb;
	size_t			i;

	desta = (unsigned char *)dest;
	srcb = (unsigned char *)src;
	i = 0;
	if ((size_t)(dest - src) < len)
	{
		while (i < len)
		{
			desta[len - i - 1] = srcb[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			desta[i] = srcb[i];
			i++;
		}
	}
	return (dest);
}
