/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 18:00:44 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/08 14:04:03 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	try;

	try = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (i < size && dst[i])
		i++;
	if (dst[i] != '\0')
		return (size + ft_strlen(src));
	j = 0;
	while (i + j < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (try);
}
