/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 19:19:12 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/07 17:09:03 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
		i = 1;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static char	ft_base(int n, int base)
{
	int temp;
	int con;

	temp = n % base;
	if (n >= 0)
		con = (temp > 9) ? temp - 10 + 'A' : temp + '0';
	else
	{
		temp = -temp;
		con = (temp > 9) ? temp - 10 + 'A' : temp + '0';
	}
	return (con);
}

char		*ft_itoa_base(int n, int base)
{
	size_t	a;
	char	*string;
	size_t	b;

	if (base <= 1 || base >= 37)
		return (NULL);
	b = 0;
	a = ft_numlen(n, base);
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
		string[a - 1] = ft_base(n, base);
		n /= base;
		a--;
	}
	return (string);
}
