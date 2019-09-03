/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/03 19:41:39 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        left_padding_float(t_container *list, t_number number, double long i)
{

}


void         f_float(t_container *list)
{
    long double i;
    int length;
    t_number number;
    unsigned long long  rest;

    number.number = 0;
    i = va_arg(list->ap, long double);
    number.sign = 0;
        if (i < 0)
    {
        i = -i;
        number.sign = 1;
    }

    if (list->flags & MIN)
        left_padding_float(list, number, i);
    else
        right_padding_float(list, number, i);
    return;
}