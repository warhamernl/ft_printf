/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:57:40 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/07 16:10:11 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_string;

	i = 0;
	if (!s)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * len + 1);
	if (!new_string)
		return (NULL);
	while (i < (unsigned int)len)
	{
		new_string[i] = s[start];
		start++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
