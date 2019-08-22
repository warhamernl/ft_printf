/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:22 by mark           #+#    #+#                */
/*   Updated: 2019/08/22 20:38:31 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_char(t_container *list, t_buff *buff)
{
    char c;
    printf("\n%s\n", buff->buff);
    c = va_arg(list->ap, int);
    if (list->width == -1)
        buff->buff[buff->i] = c;
    else
    {
        if(list->flags & MIN)
            left_padding(buff, &c, list, 0);
    //    else
      //      right_padding(buff, &c, list, 0);
    }
     printf("\n%s\n", buff->buff);
}