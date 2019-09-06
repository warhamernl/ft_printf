/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/06 21:19:13 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double      remaining(long double remaining)
{
    while (remaining >= (long double)1000)
        remaining -= (long double)1000;
    while (remaining >= (long double)100)
        remaining -= (long double)100;
    while (remaining >= (long double)10)
        remaining -= (long double)10;
    while (remaining >= (long double)1)
        remaining -= (long double)1;
    return (remaining);
}

void        left_padding_float(t_container *list, t_number number, double long i)
{

}

void        left_padding_float(t_container *list, t_number number, double long i)
{

}


void         f_float(t_container *list)
{ 
    long double i;
    int length;
    t_number number;
    double  remaining;

    i = va_arg(list->ap, long double); 
    number.sign = 0;
    if (i < 0)
    {
        i = -i;
        number.sign = 1;
    }
    if (list->precision == -1)
        list->precision = 6;
    number.number = (unsigned long long)i;
    if (list->lengthmod & LEN_FL)
        number.number = (unsigned long long)(double)i;
    remaining = decimal(remaining);
    if (list->flags & MIN)
        left_padding_float(list, number, remaining);
    else
        right_padding_float(list, number, remaining);
    return;
}