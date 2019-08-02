/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 15:19:42 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/01 13:41:15 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	int i;
	int j;

	i = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == substr[j])
		{
			j++;
			if (substr[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
