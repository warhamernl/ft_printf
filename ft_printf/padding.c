/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:56:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/27 01:30:41 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     add_zero(t_container *list, int amount)
{
    int i;

    i = 0;
    if (amount <= 0)
        return;
    while (i < amount)
    {
        addbuff(list, '0');
        i++;
    }
}

void     add_space(t_container *list, int amount)
{
    int i;

    i = 0;
    if (amount <= 0)
        return;
    while (i < amount)
    {
        addbuff(list, ' ');
        i++;
    }
}

void    left_padding(char *str, t_container *list)
{
    int amount;
    int max;

    max = INT_MAX;
    if (list->precision != -1 && list->con == 1)
        max = list->precision;
    printf("\nmax %d\n", max);
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

void    right_padding(char *str, t_container *list)
{
    int amount;
    int max;

    amount = 0;
    max = INT_MAX;
    if (list->width != -1)
        amount = list->width - ft_strlen(str) + 1;
    if (list->precision != -1 && list->con == 1)
        max = list->precision;
       printf("\nmax %d\n %d conversion \n amount %d\n", max, list->con, amount);
    if (list->flags & NUL && list->width != -1)
        add_zero(list, amount);
    if (list->width != -1)
        add_space(list, amount);
    amount = 0;
    while(*str && amount < max)
    {
        addbuff(list, *str);
        str++;
        amount++;
    }
}