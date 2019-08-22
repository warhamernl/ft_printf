/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:56 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/22 19:55:13 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_string(t_container *list, t_buff *buff)
{
    char *str;

    str = va_arg(list->ap, char *);
    if (list->flags & MIN)
        left_padding(buff, str, list, 1);
   // else
     //   right_padding(buff, i, str, 1);
}