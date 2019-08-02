/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:22:24 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 16:58:15 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		j;
	size_t	a;

	j = 0;
	i = 0;
	a = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && a < n)
	{
		if (haystack[i] == needle[j] && needle[j + 1] == '\0')
		{
			return ((char *)&haystack[i - j]);
		}
		if (haystack[i] == needle[j])
			j++;
		i++;
		a++;
	}
	return (NULL);
}
