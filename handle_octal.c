/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_octal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:23:49 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/16 16:20:18 by mlokhors      ########   odam.nl         */
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
void          right_padding_pf_base(t_container *list, t_number number, int letter_case)
{
    int amount;

    if (number.length > list->precision)
        amount = number.length;
    else
        amount = list->precision;
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE || list->flags & HASH)
    {
        if (list->con == 6 || list->con == 7)
            list->width--;
        list->width--;
    }
    while (list->width > number.length && list->flags & NUL)
    {
        addbuff(list, '0');
        list->width--;
    }
    while(list->width > amount && !(list->flags & NUL))
    {
        addbuff(list, ' ');
        amount++;
    }
    check_flags(list, number);
    ft_itoa_base_len(list, number, letter_case);
}
void          left_padding_pf_base(t_container *list, t_number number, int letter_case)
{
    int amount;

    if (number.length > list->precision)
        amount = number.length;
    else
        amount = list->precision;
    check_flags(list, number);
    while (list->width > number.length && list->flags & NUL)
    {
        addbuff(list, '0');
        list->width--;
    }
    while(list->width > amount && !(list->flags & NUL))
    {
        addbuff(list, ' ');
        amount++;
    }
    ft_itoa_base_len(list, number, letter_case);
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE || list->flags & HASH)
    {
        if (list->con == 6 || list->con == 7)
            list->width--;
        list->width--;
    }
}

void         f_octal(t_container *list)
{
    unsigned int i;
    t_number number;

    i = va_arg(list->ap, unsigned long long);
    number.sign = 0;
    number.base = 8;
    number.number = i;

    cast_itoa_pf_base(list, &number);

    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, 0);
    else
        right_padding_pf_base(list, number, 0);
    return;
}


