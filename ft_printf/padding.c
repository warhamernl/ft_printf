/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:56:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/23 11:37:23 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     add_zero(t_buff *buff, t_container *list, int amount)
{
    int i;

    i = 0;
    list->width -= amount;
    while (i < list->width)
    {
        buff->buff[buff->i] = '0';
        i++;
        buff->i++;
    }
 //   printf("\nadd_zero%d\n", buff->i);
}

void     add_space(t_buff *buff, t_container *list, int amount)
{
    int i;

    i = 0;
    list->width -= amount;
    while (i < list->width)
    {
        buff->buff[buff->i] = ' ';
        i++;
        buff->i++;
    }
 //   printf("\nadd_space%d\n", buff->i);
}

void    left_padding(t_buff *buff, char *str, t_container *list, int check)
{
    int amount;

    amount = 0;
    if (check == 0)
    {
        while(*str)
        {
            buff->buff[buff->i] = *str;
            str++;
            buff->i++;
            amount++;
        }
        if (list->flags & NUL)
            add_zero(buff, list, amount);
        else
            add_space(buff, list, amount);
    }

}