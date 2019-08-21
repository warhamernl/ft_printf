/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 18:46:30 by mark           #+#    #+#                */
/*   Updated: 2019/08/21 18:48:42 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = 0;
    list->width = 0;
}

void            check_lenthmod(char **str, t_container *list)
{
    if (**str == 'h')
    {
        if ( **str + 1 == 'h')
            list->lengthmod = LEN_H;
        else
            list->lengthmod = LEN_HH;
    }
    if (**str == 'l')
    {
        if ( **str + 1 == 'l')
            list->lengthmod = LEN_L;
        else
            list->lengthmod = LEN_LL;
    }
    if (**str == 'L')
    {
            list->lengthmod = LEN_FL;
    }
}

void            check_widthprecision(char **str, t_container *list)
{
    if (**str == '*')
        list->width = va_arg(list->ap, int);
    if (**str >= '0' && **str <= '9')
        list->width = ft_atoi(*str);
    if (**str == '.')
    {
        if (**str == '*')
            list->precision = va_arg(list->ap, int);
        if (**str >= '0' && **str <= '9')
            list->precision = ft_atoi(*str);
    }
    
}

void            check_flag(char **str, t_container *list)
{
    while (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
    {   
        if (**str == '#')
            list->flags |= HASH;
        if (**str == '0')
            list->flags |= NUL;
        if (**str == '-')
            list->flags |= MIN;
        if (**str == ' ')
            list->flags |= SPACE;
        if (**str == '+')
            list->flags |= PLUS;
        *str++;
    }   

}
