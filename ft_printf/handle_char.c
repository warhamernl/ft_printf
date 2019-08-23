/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:22 by mark           #+#    #+#                */
/*   Updated: 2019/08/23 11:27:16 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_char(t_container *list, t_buff *buff)
{
    char c[2];
    char *pointer;
 //   printf("\n%s\n", buff->buff);
    c[0] = va_arg(list->ap, int);
    c[1] = '\0';
    pointer = c;
    if (list->width == -1)
    {
        buff->buff[buff->i] = c[0];
        buff->i++;
    }   
    else
    {
        if(list->flags & MIN)
            left_padding(buff, pointer, list, 0);
    //    else
      //      right_padding(buff, &c, list, 0);
    }
 //    printf("\n%s\n", buff->buff);
}