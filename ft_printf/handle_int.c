/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:57:56 by mark           #+#    #+#                */
/*   Updated: 2019/08/27 23:53:53 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void         f_int(t_container *list)
{
    
    int i;
    int leng;
    int nega;
    char *str;

    i = va_arg(list->ap, int);
    if ( i < 0)
    {
        nega = 1;
        i = -i;
    }
    leng = ft_numlen_ull((unsigned long long) i, 10, nega);
    if (list->flags == 0)
    {
        
    }
    if (list->flags & MIN && list->flags & NUL || list->flags & NUL && list->precision != 0)
        list->flags |= ~NUL;
    printf("%d\n", list->i);
    return;
}