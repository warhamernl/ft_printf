/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_shex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:24:33 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/22 20:18:13 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_hex(t_container *list, t_buff *buff)
{
    /*
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 16, 0);
    write(1, str, ft_strlen(str));
    return;
    */
       printf("%d\n", list->width);
    printf("%d\n", buff->i);
}