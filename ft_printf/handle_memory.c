/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_memory.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:14 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/23 13:31:01 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_void_pointer(t_container *list)
{
    /* 
    char *str;

    str = va_arg(list->ap, char *);
    write(1, str, sizeof(str));*/
        printf("%d\n", list->width);
    printf("%d\n", list->i);
    return;
}