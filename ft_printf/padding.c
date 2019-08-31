/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:56:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/31 22:26:06 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void            add_str(t_container *list,const char *str)
{
    while(*str)
    {
        addbuff(list, *str);
        str++;
    }
}

void         check_flags(t_container *list, t_number number)
{
const char *str[] = {
  [0] = "0",
  [1] = "0x",
  [2] = "0X",
};
        if (number.sign == 1)
            addbuff(list, '-');
        else if (list->flags & PLUS && list->con == 3)
            addbuff(list, '+');
        else if (list->flags & SPACE)
            addbuff(list, ' ');
        else if (list->flags & HASH )
        {
            if (list->con == 5)
                add_str(list, str[0]);
            else if (list->con == 6)
                add_str(list, str[1]);
            else if (list->con == 7)
                add_str(list, str[2]);
        }
}

void     add_zero(t_container *list, int amount)
{
    int i;

    i = 0;
    if (list->width != -1)
        list->width -= amount;
    else
        list->width = amount;
    while (i < list->width)
    {
        addbuff(list, '0');
        i++;
    }
}

void     add_space(t_container *list, int amount)
{
    int i;

    i = 0;
    list->width -= amount;
    while (i < list->width)
    {
        addbuff(list, ' ');
        i++;
    }
}
