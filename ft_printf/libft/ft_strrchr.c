/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 15:03:31 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 16:57:01 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	a;
	char	*b;

	b = NULL;
	i = 0;
	a = (char)ch;
	while (str[i])
	{
		if (str[i] == a)
			b = (char *)&str[i];
		i++;
	}
	if (str[i] == a)
		b = (char *)&str[i];
	return (b);
}
