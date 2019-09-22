/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_octal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:23:49 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/22 13:34:57 by mark          ########   odam.nl         */
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

int            get_amount_pf(t_container *list, t_number number)
{
    if ((number.number == 0 && list->precision == 0) || (list->con != 5 && list->flags & HASH && number.number == 0 && list->precision == 0))
        return (0);
    else if (number.length > list->precision)
        return (number.length);
    else
        return (list->precision);
}

void        check_width_pf(t_container *list, t_number number)
{
    if (number.sign == 1 || list->flags & PLUS|| list->flags & SPACE || (list->flags & HASH && number.number != 0))
    {
    if (list->con == 6 || list->con == 7)
            list->width--;
        list->width--;
    }
}

void           right_padding_pre_zero(t_container *list, t_number number)
{
    check_flags(list, number);
    if (list->width > number.length && list->flags & NUL)
    {
        add_zero(list, list->width - number.length);
        list->width -= number.length;
    }
}

void           pre_itoa_pf_padding(t_container *list, t_number number, int letter_case)
{
    if (list->flags & HASH && list->con == 5)
        list->precision--;
    if (number.length < list->precision)
        add_zero(list, list->precision - number.length);
    ft_itoa_base_len(list, number, letter_case);
}

void          right_padding_pf_base(t_container *list, t_number number, int letter_case)
{
    int amount;

    amount = get_amount_pf(list, number);
    check_width_pf(list, number);    
    if (list->flags & NUL )
        right_padding_pre_zero(list, number);
    else
    {
        if (list->width > amount && !(list->flags & NUL))
            add_space(list, list->width - amount);
        check_flags(list, number);
    }
    if (!(number.number == 0 && list->precision == 0) ||
        (list->con == 5 && list->flags & HASH && number.number == 0 && list->precision == 0 ))
        pre_itoa_pf_padding(list, number, letter_case);
}


void          left_padding_pf_base(t_container *list, t_number number, int letter_case)
{
    int amount;

    amount = get_amount_pf(list, number);
    check_width_pf(list, number);
    check_flags(list, number);
    if (!( number.number == 0 && list->precision == 0 ))
        pre_itoa_pf_padding(list, number, letter_case);
    if (list->width > amount)
        add_space(list, list->width - amount);
}

void         f_octal(t_container *list)
{
    unsigned long long i;
    t_number number;

    i = va_arg(list->ap, unsigned long long);
    number.sign = 0;
    number.base = 8;
    number.number = i;
    if (list->flags & NUL && list->flags & MIN)
        list->flags &= ~(NUL);
    cast_itoa_pf_base(list, &number);
    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pf_base(list, number, 0);
    else
        right_padding_pf_base(list, number, 0);
    return;
}


