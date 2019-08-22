/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 18:23:42 by mark           #+#    #+#                */
/*   Updated: 2019/08/22 19:10:43 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/* 
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

// size_t		ft_itoa_base_len(char buf_out[128], t_number *number);




size_t		*ft_itoa_base_len(t_buff buff, t_number *number, int *i)
{
	int	length;
	int b;
	size_t	count;

	if (number->base <= 1 || number->base >= 37)
		return (NULL);
	length = ft_numlen(number->number, number->base);
	b = length;
	if (number->number == 0)
		length = 1;
	if (number->nega == 1)
		buff.buff[0] = '-';
	length += number->nega;
	while (number->nega != length)
	{
		buff.buff[number->nega + *i] = ft_base(&number->number, number->base, &b);
		b--;
		*i++;
	}
	return (buff);
}

*/