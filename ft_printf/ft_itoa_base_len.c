/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 18:23:42 by mark           #+#    #+#                */
/*   Updated: 2019/08/19 18:04:03 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

static char	ft_base(int *n, int base, int *b)
{
	int store;
	int temp;
	int con;
	char basesmall[]="0123456789abcdefghijklmnopqrstuvwxyz";
//	char basebig[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	store = *n / ft_power(base, (*b - 1));
	temp = store % base;
	if (*n >= 0)
		con = basesmall[temp];
	else
		con = basesmall[temp];
	*n -= ft_power(base, *b - 1) * temp;
	return (con);
}

typedef struct	s_number
{
	unsigned long long	value;
	int					positive;
	int					base;
}				t_number;


// size_t		ft_itoa_base_len(char buf_out[128], t_number *number);




char		*ft_itoa_base_len(int n, int base, int nega)
{
	int	a;
	int b;
	char	*string;

	if (base <= 1 || base >= 37)
		return (NULL);
	a = ft_numlen(n, base);
	b = a;
	if (n == 0)
		a = 1;
	string = ft_strnew(a + nega);
	if (!string)
		return (NULL);
	if (nega == 1)
		string[0] = '-';
	a += nega;
	while (nega != a)
	{
		string[nega] = ft_base(&n, base, &b);
		b--;
		nega++;
	}
	return (string);
}