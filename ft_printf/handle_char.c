/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:22 by mark           #+#    #+#                */
/*   Updated: 2019/08/26 22:12:56 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_char(t_container *list)
{
    char c;
 //   printf("\n%s\n", buff->buff);
    c = va_arg(list->ap, int);
    if (list->width == -1)
        addbuff(list, c);  
    else
    {
        if(list->flags & MIN)
            left_padding(&c, list);
        else
            right_padding(&c, list);
    }
 //    printf("\n%s\n", buff->buff);
}