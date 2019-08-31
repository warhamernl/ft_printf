/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_octal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:23:49 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/01 00:02:40 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void        cast_itoa_pf_base(t_container *list, t_number *number)
{
    if (list->lengthmod == 0)
        number->number = (unsigned long long)(unsigned int)number->number;
    else if (list->lengthmod & LEN_H)
        number->number = (unsigned long long)(unsigned short int)number->number;
    else if(list->lengthmod & LEN_HH)
        number->number = (unsigned long long)(unsigned char)number->number;
    else if(list->lengthmod & LEN_L)
        number->number = (unsigned long long)(unsigned long int)number->number;
    else if(list->lengthmod & LEN_LL)
        number->number = (unsigned long long)number->number;
}
void          right_padding_pf_base(t_container *list, t_number number, int length, int letter_case)
{
    int amount;

    if (length > list->precision)
        amount = length;
    else
        amount = list->precision;
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE || list->flags & HASH)
    {
        if (list->con == 6 || list->con == 7)
            list->width--;
        list->width--;
    }
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
    ft_itoa_base_len(list, number, length, letter_case);
}
void          left_padding_pf_base(t_container *list, t_number number, int length, int letter_case)
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
    ft_itoa_base_len(list, number, length, letter_case);
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE || list->flags & HASH)
    {
        if (list->con == 6 || list->con == 7)
            list->width--;
        list->width--;
    }
    while(list->width > amount)
    {
        addbuff(list, ' ');
        amount++;
    }
}

void         f_octal(t_container *list)
{
    unsigned int i;
    int length;
    t_number number;

    i = va_arg(list->ap, int);
    number.sign = 0;
    number.base = 8;
    number.number = (unsigned long long)i;

    cast_itoa_pf_base(list, &number);

    length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, length, 0);
    else
        right_padding_pf_base(list, number, length, 0);
    return;
}


