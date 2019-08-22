/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_memory.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:14 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/22 20:17:11 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_void_pointer(t_container *list, t_buff *buff)
{
    /* 
    char *str;

    str = va_arg(list->ap, char *);
    write(1, str, sizeof(str));*/
        printf("%d\n", list->width);
    printf("%d\n", buff->i);
    return;
}