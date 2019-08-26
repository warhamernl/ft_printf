/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/08/27 01:41:16 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void         f_int(t_container *list)
{
    /*
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 10, 0);
    write(1, str, ft_strlen(str));
    */
       printf("%d\n", list->width);
    printf("%d\n", list->i);
    return;
}