/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 16:39:51 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/08 11:13:36 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		i = 1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	size_t	a;
	char	*string;
	size_t	b;

	b = 0;
	a = ft_numlen(n);
	if (n == 0)
		a = 1;
	string = ft_strnew(a);
	if (!string)
		return (NULL);
	if (n < 0)
	{
		b = 1;
		string[0] = '-';
	}
	while (a != b)
	{
		string[a - 1] = (n >= 0 ? (n % 10) : -(n % 10)) + '0';
		n /= 10;
		a--;
	}
	return (string);
}
