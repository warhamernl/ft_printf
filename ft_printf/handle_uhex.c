/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_uhex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:26:13 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/09 02:03:40 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_uhex(t_container *list)
{
    unsigned int i;
    t_number number;

    i = va_arg(list->ap, unsigned int);
    number.sign = 0;
    number.base = 16;
    number.number = (unsigned long long)i;
    cast_itoa_pf_base(list, &number);
    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, 1);
    else
        right_padding_pf_base(list, number, 1);
    return;
}
