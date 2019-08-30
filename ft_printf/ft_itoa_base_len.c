/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 18:23:42 by mark           #+#    #+#                */
/*   Updated: 2019/08/29 22:03:55 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_base(unsigned long long *n, int base, int *b)
{
	int store;
	int temp;
	int con;
	char basesmall[]="0123456789abcdefghijklmnopqrstuvwxyz";
//	char basebig[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	store = *n / ft_power(base, (*b - 1));
	temp = store % base;
	con = basesmall[temp];
	*n -= ft_power(base, *b - 1) * temp;
	return (con);
}

void		ft_itoa_base_len(t_container *list, t_number number, int len)
{
	int b;

	b = len;
	if (number.number == 0)
		len = 1;
	len += number.sign;
	while (number.sign != len)
	{
		addbuff(list, ft_base(&(number.number), number.base, &b));
		len--;
		b--;
	}
	return ;
}

