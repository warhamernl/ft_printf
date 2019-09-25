/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listbuff.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 20:30:38 by mark           #+#    #+#                */
/*   Updated: 2019/09/25 06:27:07 by mark          ########   odam.nl         */
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
            list->writer(list);
/*       {
            write(1, list->buff, BUFF_SIZE -1);
            ft_memset(list->buff, 0, BUFF_SIZE);
            list->i = 0;
        } */

}

void            rrmaining(t_container list)
{
    write(1, list.buff, list.i);
}

void           writer_fd(t_container *list)
{
    list->total += list->i;
    write(list->fd, list->buff, list->i - 1);
    ft_memset(list->buff, 0, BUFF_SIZE);
    list->i = 0;
}

void            writer_str(t_container *list)
{
    list->total += list->i;
    list->str = ft_strjoin(list->str, list->buff);
    ft_memset(list->buff, 0, BUFF_SIZE);
    list->i = 0;
}       


