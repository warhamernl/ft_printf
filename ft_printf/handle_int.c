/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/08/23 13:30:41 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_iint(t_container *list)
{
/*
    int i;
    char str[128];

    ft_memset(str, 0, 128);
    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 10, 0);
    write(1, str, ft_strlen(str));
   */ 
    printf("%d\n", list->width);
    printf("%d\n", list->i);
    return;
}

void         f_int(t_container *list)
{
    /*
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 10, 0);
    write(1, str, ft_strlen(str));
    */
       printf("%d\n", list->width);
    printf("%d\n", list->i);
    return;
}