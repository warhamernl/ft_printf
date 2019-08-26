/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:56 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/27 01:35:37 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void    left_padding_str(char *str, t_container *list)
{
    int amount;
    int max;

    max = INT_MAX;
    if (list->precision != -1)
        max = list->precision;
    amount = 0;
    while(*str && amount < max)
    {
        addbuff(list, *str);
        str++;
        amount++;
    }
    if (list->flags & NUL && list->width != -1)
        add_zero(list, list->width - amount);
    if (list->width != -1)
        add_space(list, list->width - amount);

}

void    right_padding_str(char *str, t_container *list)
{
    int amount;
    int max;

    amount = 0;
    max = INT_MAX;
    if (list->width != -1)
        amount = list->width - ft_strlen(str) + 1;
    if (list->precision != -1)
        max = list->precision;
    if (list->flags & NUL && list->width != -1)
        add_zero(list, list->width - max);
    if (list->width != -1)
        add_space(list, list->width - max);
    amount = 0;
    while(*str && amount < max)
    {
        addbuff(list, *str);
        str++;
        amount++;
    }
}


void         f_string(t_container *list)
{
    char *str;

    str = va_arg(list->ap, char *);
    if (list->width != -1 || list->precision != -1)
    {
        if (list->flags & MIN)
            left_padding_str(str, list);
         else
            right_padding_str(str, list);
    }
    else
    {
        while (*str)
        {
            addbuff(list, *str);
            str++;
        }
    }    
}