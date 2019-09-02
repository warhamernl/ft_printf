/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/02 22:51:24 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_float(t_container *list)
{
    long double i;
    int length;
    t_number number;

    length = 0;
    i = va_arg(list->ap, long double);
    number.sign = 0;
        if (i < 0)
    {
        i = -i;
        number.sign = 1;
    }
    number.base = 10;

    cast_itoa(list, &number);
    length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_int(list, number, length);
    else
        right_padding_int(list, number, length);
    return;
}