/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/08 17:07:18 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

 static const t_pair g_lookup_array[] = {
 { 'c', E_CHAR },
 { 's', E_STRING },
 { 'p', E_VOID_POINTER },
 { 'i', E_IINT },
 { 'd', E_INT },
 { 'o', E_OCTAL },
 { 'x', E_HEX },
 { 'X', E_UHEX },
 { 'f', E_FLOAT },
 };
 
 t_desc find_descriptor(char c)
 {
    size_t i = 0;
    size_t length = sizeof(g_lookup_array) / sizeof(t_pair); // 3
    while (i < length)
    {
        t_pair pair = g_lookup_array[i];
        if (c == pair.key)
        {
            return (pair.desc);
        }
        i++;
    }
    return (E_INVALID);
 }

int             check_conversion(char **str, t_container *list)
{

}
/*
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
        list->width = va_arg(*list->ap, int);
    if (**str >= '0' && **str <= '9')
        list->width = ft_atoi(*str);
    if (**str == '.')
    {
        if (**str == '*')
            list->precision = va_arg(*list->ap, int);
        if (**str >= '0' && **str <= '9')
            list->precision = ft_atoi(*str);
    }
    
}

void            check_flag(char **str, t_container *list)
{
    while (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
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

}
void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = 0;
    list->width = 0;
}*/

int             parser(char *str, t_container *list)
{
    empty(list);
//   if (*str == '#' || *str == '0' || *str == '-' || *str == ' ' || *str == '+')
//       check_flag(&str, list);
//   if  (*str >= '0' && *str <= '9' || *str == '.')
//      check_widthprecision(&str, list);
//   if (*str ==  'h' || *str == 'l' || *str == 'L')
//        check_lenthmod(&str, list);   
    if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'|| *str == 'i'|| *str == 'o' || *str == 'x'|| *str == 'X' || *str == 'f')
    {
        if (check_conversion(&str, list) == 0);
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
                continue;
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
