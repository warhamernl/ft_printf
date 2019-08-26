/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:56 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/26 23:27:34 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_string(t_container *list)
{
    char *str;

    str = va_arg(list->ap, char *);
    printf("\nstring argu str %s\n", str);
    if (list->width != -1 || list->precision != -1)
    {
        if (list->flags & MIN)
            left_padding(str, list);
         else
            right_padding(str, list);
    }
    else
    {
        while (*str)
        {
            addbuff(list, *str);
            str++;
        }
    }    
}