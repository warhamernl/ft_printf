/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:40:31 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 21:20:41 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	size_t			i;
	size_t			j;

	if (!s || !f)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	new_string = (char *)malloc(sizeof(char) * j + 1);
	if (!new_string)
		return (NULL);
	while (i < j)
	{
		new_string[i] = (*f)(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
