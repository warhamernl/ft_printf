/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/08/30 23:18:43 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        cast_itoa(t_container *list, t_number *number)
{
    if (list->lengthmod == 0)
        number->number = (unsigned long long)(int)number->number;
    else if (list->lengthmod & LEN_H)
        number->number = (unsigned long long)(short int)number->number;
    else if(list->lengthmod & LEN_HH)
        number->number = (unsigned long long)(signed char)number->number;
    else if(list->lengthmod & LEN_L)
        number->number = (unsigned long long)(long int)number->number;
    else if(list->lengthmod & LEN_LL)
        number->number = (unsigned long long)(long long int)number->number;
}
void          right_padding_int(t_container *list, t_number number, int length)
{
    int amount;

    if (length > list->precision)
        amount = length;
    else
        amount = list->precision;
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE)
        list->width--;
    while(list->width > amount)
    {
        addbuff(list, ' ');
        amount++;
    }
    check_flags(list, number);
    while (list->precision > length)
    {
        addbuff(list, '0');
        list->precision--;
    }
    ft_itoa_base_len(list, number, length, 0);
}
void          left_padding_int(t_container *list, t_number number, int length)
{
    int amount;

    if (length > list->precision)
        amount = length;
    else
        amount = list->precision;
    check_flags(list, number);
    while (list->precision > length)
    {
        addbuff(list, '0');
        list->precision--;
    }
    ft_itoa_base_len(list, number, length, 0);
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE)
        list->width--;
    while(list->width > amount)
    {
        addbuff(list, ' ');
        amount++;
    }
}

void         f_int(t_container *list)
{
    int i;
    int length;
    t_number number;

    length = 0;
    i = va_arg(list->ap, int);
    number.sign = 0;
        if (i < 0)
    {
        i = -i;
        number.sign = 1;
    }
    number.base = 10;
    number.number = (unsigned long long)i;
    cast_itoa(list, &number);
    length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_int(list, number, length);
    else
        right_padding_int(list, number, length);
    return;
}

