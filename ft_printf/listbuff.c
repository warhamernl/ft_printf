/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listbuff.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 20:30:38 by mark           #+#    #+#                */
/*   Updated: 2019/09/22 16:46:16 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = -1;
    list->width = -1;
    list->bit = 0;
}

void            addbuff(t_container *list, char c)
{

        list->buff[list->i] = c;
        list->i++;
        if (list->i == BUFF_SIZE)
        {
            write(1, list->buff, BUFF_SIZE -1);
            ft_memset(list->buff, 0, BUFF_SIZE);
            list->i = 0;
        }

}

void            rrmaining(t_container list)
{
    write(1, list.buff, list.i);
}