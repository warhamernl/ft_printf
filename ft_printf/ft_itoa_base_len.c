/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 18:23:42 by mark           #+#    #+#                */
/*   Updated: 2019/08/17 20:27:32 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_numlen(unsigned long long nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static char	ft_base(unsigned long long n,unsigned int base,unsigned int times)
{
	unsigned long long temp;
	unsigned long long con;

	if (n > base)
		temp = n / ft_power(base, times - 1);
	else
		temp = n % base;
	if (temp > 9)
		con = temp - 10 + 'A';
	else
		con = temp + '0';
	return (con);
}

char		*ft_itoa_base_len(unsigned long long n, int base, int nega)
{
	int a;
	char *string;
	int b;
	int c;

	a = ft_numlen(n, base);
//	printf("%d a\n", a);
	b = a + nega;
	string = ft_strnew(a + nega);
	if (base <= 1 || base >= 37 || !string)
		return (NULL);
	if (nega == 1)
		string[0] = '-';
	printf("%d\n", nega);
	printf("%d\n", a);
	while (nega != b)
	{
		string[nega] = ft_base(n, base, a);
		if (a - 1 <= 0)
			c = 0;
		else
			c = ft_power(base, a - 1);
		n = n - c;
		nega++;
		a--;
	}
	return (string);
}


int		main(void)
{
	unsigned long long n;

	n = 14;

	printf("%s",ft_itoa_base_len(n, 16, 1));

}