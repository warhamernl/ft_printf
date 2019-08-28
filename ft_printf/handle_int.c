/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/08/28 18:41:56 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_int(t_container *list)
{
    int sign;
    int i;
    int length;
    t_number number;

    i = va_arg(list->ap, int);
    sign = 0;
    if (list->flags & PLUS || i < 0)
    {
        sign = 1;
        isnegative(&number, &i);
    }
    number.base = 10;
    number.base = (unsigned long long)i;
    if (list->width > (sign + list->precision))
        handle_width(list, number);
    else if (list->precision > list->width)
        handle_precision(list, number);
    else
        normal(list, number);
    return;
}