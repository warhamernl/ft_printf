/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_bits2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 11:57:59 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/23 11:59:10 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_bits_str(t_container *list, t_bits sort)
{
    char *str;
    int i;

    i = 0;
    str = va_arg(list->ap, char *);
    while (*str)
    {
        sort.notsign = *str;
        i = 0;
        while (i < 8)
        {
            if (sort.notsign & (1LL << (8 - 1 - i)))
                addbuff(list, '1');
            else
                addbuff(list, '0');
            i++;
        }
        str++;
        if (*str != '\0')
            addbuff(list, ' ');
    }
    return ;
}