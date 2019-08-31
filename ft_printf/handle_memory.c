/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_memory.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:14 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/31 20:58:51 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_void_pointer(t_container *list)
{
    void *pointer;
    t_number number;
    int length;
    char *str;

    str ="0x";
	if (list->width > 14)
		add_space(list, 14);
    add_str(list, str);
    pointer = va_arg(list->ap, void *);
    number.number = (unsigned long long)pointer;
    number.sign = 0;
    number.base = 16;
    length = ft_numlen_ull(number.number, number.base);
    ft_itoa_base_len(list, number, length, 0);

    return;
}