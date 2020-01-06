/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 14:54:44 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 13:21:17 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t count)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (count == 0)
		return (0);
	while (i < count && *a == *b)
	{
		i++;
		if (i < count)
		{
			a++;
			b++;
		}
	}
	return ((int)(*a - *b));
}
