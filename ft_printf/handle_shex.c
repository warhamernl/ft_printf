/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_shex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:24:33 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/31 00:25:47 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_hex(t_container *list)
{
    unsigned int i;
    int length;
    t_number number;

    i = va_arg(list->ap, int);
    number.sign = 0;
    number.base = 16;
    number.number = (unsigned long long)i;
    cast_itoa_pf_base(list, &number);
    length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, length, 0);
    else
        right_padding_pf_base(list, number, length, 0);
    return;
}