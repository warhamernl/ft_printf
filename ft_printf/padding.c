/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:56:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/23 13:46:55 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     add_zero(t_container *list, int amount)
{
    int i;

    i = 0;
    list->width -= amount;
    while (i < list->width)
    {
        list->buff[list->i] = '0';
        i++;
        list->i++;
    }
 //   printf("\nadd_zero%d\n", buff->i);
}

void     add_space(t_container *list, int amount)
{
    int i;

    i = 0;
    list->width -= amount;
    while (i < list->width)
    {
        list->buff[list->i] = ' ';
        i++;
        list->i++;
    }
 //   printf("\nadd_space%d\n", buff->i);
}

void    left_padding(char *str, t_container *list, int check)
{
    int amount;

    amount = 0;
    if (check == 0)
    {
        while(*str)
        {
            list->buff[list->i] = *str;
            str++;
            list->i++;
            amount++;
        }
        if (list->flags & NUL)
            add_zero(list, amount);
        else
            add_space(list, amount);
    }

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
            list->buff[list->i] = *str;
            list->i++;
            str++;
        }        
    }
}