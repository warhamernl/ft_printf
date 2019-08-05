/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/05 15:00:28 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>




int             parser(char *str, t_container *list)
{
    list->precision = 0;
    list->width = 0;
    if (*str == '#' || *str == '0' || *str == '-' || *str == ' ' || *str == '+')
        check_flag(&str, list);
    if  (*str >= '0' && *str <= '9' || *str == '.')
        check_widthprecision(&str, list);
    if (*str ==  'h' || *str == 'l' || *str == 'L')
        check_lenthmod(&str, list);   
    if (*str == 'c' || *str == 'd' || *str == 'e' || *str == 'E' || *str == 'f' || *str == 's')
    {
        check_conversion(&str, list);
        return (0);
    }
    return (-1);
}


int             ft_printf(char *str, ...)
{
    t_container *list;
    va_start(*list->ap, str);

    while (*str)
    {
      if (*str == '%')
        {
            str++;
            if (*str == '%')
            {
                write(1, '%', 1);
                str++;
            }
            parser(str, list);
            while(*str != ' ')
                str++;
        }
        write(1, str, 1);
        str++;
    }
    va_end(*list->ap);
    return (0);        
}


int     main(void)
{
    ft_printf("je moeder aan %d de %d poeder ", 5 , 10);

    return(0);
}
