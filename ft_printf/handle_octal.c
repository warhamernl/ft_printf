/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_octal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:23:49 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/22 20:17:45 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_octal(t_container *list, t_buff *buff)
{
    /*
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 8, 0);
    write(1, str, ft_strlen(str));
    return;
    */
       printf("%d\n", list->width);
    printf("%d\n", buff->i);
}