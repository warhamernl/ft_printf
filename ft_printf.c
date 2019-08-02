/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/02 17:32:29 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int             ft_printf(const char *str, ...)
{
    va_list ap;
    int d;
    char c, *s;

    d = 0;
    va_list argc;
    va_start(argc, str);
    while (*str
    {
        if (*str == '%')
        {
            
        }
        str++;
    }
    va_end(argc);
    return (0);        
}


int     main(void)
{


    return(0);
}