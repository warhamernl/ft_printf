/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_memory.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:14 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/20 12:58:06 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  right_padding_pointer(t_container *list, t_number number, char *str)
{
    if (list->width > number.length + 2)
        add_space(list, list->width - number.length - 2);
    add_str(list, str);
    if (list->precision != 0)
        ft_itoa_base_len(list, number, 0);
}


void  left_padding_pointer(t_container *list, t_number number, char *str)
{
    add_str(list, str);
    q
    yif (list->precision != 0)
        ft_itoa_base_len(list, number, 0);
    if (list->width > number.length + 2)
        add_space(list, list->width - number.length - 2);
}
void         f_void_pointer(t_container *list)
{
    void *pointer;
    t_number number;
    char *str;

    str ="0x";
    pointer = va_arg(list->ap, void *);
    number.number = (unsigned long long)pointer;
    number.sign = 0;
    number.base = 16;
    number.length = ft_numlen_ull(number.number, number.base);
    if (list->flags & MIN)
        left_padding_pointer(list, number, str);
    else
        right_padding_pointer(list, number, str);
    return;
}