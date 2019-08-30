/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 18:23:42 by mark           #+#    #+#                */
/*   Updated: 2019/08/30 15:14:23 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_base(unsigned long long *n, int base, int *b, int case)
{
	int store;
	int temp;
	int con;
	char	*base_number[2];
	base_number[0]="0123456789abcdefghijklmnopqrstuvwxyz";
	base_number[1]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	store = *n / ft_power(base, (*b - 1));
	temp = store % base;
	con = base_number[case][temp];
	*n -= ft_power(base, *b - 1) * temp;
	return (con);
}

void		ft_itoa_base_len(t_container *list, t_number number, int len, int case)
{
	int b;

	b = len;
	if (number.number == 0)
		len = 1;
	len += number.sign;
	while (number.sign != len)
	{
		addbuff(list, ft_base(&(number.number), number.base, &b, case));
		len--;
		b--;
	}
	return ;
}

