/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:56:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/29 21:58:03 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
/*
void    left_padding(char *str, t_container *list, int check)
{
    int amount;
    int max;

    max = INT_MAX;
    if (list->precision != -1 && list->con == 2)
        max = list->precision;
    amount = 0;
    while(*str && amount < max)
    {
        addbuff(list, *str);
        str++;
        amount++;
    }
    if (list->flags & NUL && list->width != -1)
        add_zero(list, amount);
    if (list->width != -1)
        add_space(list, amount);

}

void    right_padding(char *str, t_container *list, int check)
{
    int amount;

    amount = ft_strlen(str);
    if (check == 0)
    {        
        if (list->flags & NUL)
            add_zero(list, amount);
        else
            add_space(list, amount);
        while(*str)
        {
            addbuff(list, *str);
            str++;
        }        
    }
}

*/