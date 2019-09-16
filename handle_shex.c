/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_shex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:24:33 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/16 15:37:05 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_hex(t_container *list)
{
    unsigned long long i;
    t_number number;

    i = va_arg(list->ap, unsigned long long);
    number.sign = 0;
    number.base = 16;
    number.number = i;
    cast_itoa_pf_base(list, &number);
    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, 0);
    else
        right_padding_pf_base(list, number, 0);
    return;
}