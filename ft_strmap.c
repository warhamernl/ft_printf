/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 20:04:10 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 21:20:06 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new_string;
	size_t	j;

	i = 0;
	if (!s || !f)
		return (NULL);
	j = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * j + 1);
	if (!new_string)
		return (NULL);
	while (i < j)
	{
		new_string[i] = f(s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
