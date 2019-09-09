/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/09/08 15:09:43 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int         check_sign(t_number *number, int *i)
{
    if (*i < 0)
    {
        *i = -*i;
        number->sign = 1;
        return (1);
    }
    return (0);
}

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
void          right_padding_int(t_container *list, t_number number)
{
    int amount;

    if (number.length > list->precision)
        amount = number.length;
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
    while (list->precision > number.length)
    {
        addbuff(list, '0');
        list->precision--;
    }
    ft_itoa_base_len(list, number, 0);
}
void          left_padding_int(t_container *list, t_number number)
{
    int amount;

    if (number.length > list->precision)
        amount = number.length;
    else
        amount = list->precision;
    check_flags(list, number);
    while (list->precision > number.length)
    {
        addbuff(list, '0');
        list->precision--;
    }
    ft_itoa_base_len(list, number, 0);
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
    t_number number;

    i = va_arg(list->ap, int);
    number.sign = check_sign(&number, &i);
    if (list->lengthmod & NUL && list->precision != -1)
        list->lengthmod |= ~(NUL);
    number.base = 10;
    number.number = (unsigned long long)i;
    cast_itoa(list, &number);
    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_int(list, number);
    else
        right_padding_int(list, number);
    return;
}

