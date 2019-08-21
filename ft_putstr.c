/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:59:58 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/21 13:55:03 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
//
/*

//
write(1, s, ft_strlen(s));

while (1)
{
	gewrapt object;
	count++;
}

custom_write( char *mem, size_t size, *struct)
*/