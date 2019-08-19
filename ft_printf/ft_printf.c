/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/19 17:37:05 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>


void         f_uhex(t_container *list)
{
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 16, 0);
    write(1, str, ft_strlen(str));
    return;
}


void         f_float(t_container *list)
{
    printf("%d\n", list->width);
    return;
}

void         f_hex(t_container *list)
{
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 16, 0);
    write(1, str, ft_strlen(str));
    return;
}
void         f_octal(t_container *list)
{
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 8, 0);
    write(1, str, ft_strlen(str));
    return;
}
void         f_int(t_container *list)
{
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 10, 0);
    write(1, str, ft_strlen(str));
    return;
}
void         f_iint(t_container *list)
{
    int i;
    char *str;

    i = va_arg(list->ap, int);
    str = ft_itoa_base_len(i, 10, 0);
    write(1, str, ft_strlen(str));
    return;
}
void         f_string(t_container *list)
{
    char *str;

    str = va_arg(list->ap, char *);
    write(1, str, ft_strlen(str));
    return;
}
void         f_void_pointer(t_container *list)
{
    char *str;

    str = va_arg(list->ap, char *);
    write(1, str, sizeof(str));
    return;
}

void         f_char(t_container *list)
{
    char c;
    
    c = va_arg(list->ap, int);
    write(1, &c, 1);
    return;
}

static     const t_print_var var_list[] = {
        f_char,
        f_string,
        f_void_pointer,
        f_int,
        f_int,
        f_octal,
        f_hex,
        f_uhex,
        f_float
                                    };



const t_print_var functions[] = {
        f_char,
        f_string,
        f_void_pointer,
        f_int,
        f_int,
        f_octal,
        f_hex,
        f_uhex,
        f_float
                                    };

 t_pair g_lookup_array[] = {
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
    size_t i; 
    i = 0;
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
*/
void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = 0;
    list->width = 0;
}



int             parser(char *str, t_container *list)
{
    t_desc  number;
    empty(list);
    str++;
//   if (*str == '#' || *str == '0' || *str == '-' || *str == ' ' || *str == '+')
//       check_flag(&str, list);
//   if  (*str >= '0' && *str <= '9' || *str == '.')
//      check_widthprecision(&str, list);
//   if (*str ==  'h' || *str == 'l' || *str == 'L')
//        check_lenthmod(&str, list);   
    if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'|| *str == 'i'|| *str == 'o' || *str == 'x'|| *str == 'X' || *str == 'f')
    {
        number = find_descriptor(*str);
        if (number == -1)
            return(-1);
        var_list[number](list);
        return (0);
    }
    return (-1);
}
/*
void            writer(t_container list, char *str)
{
    
}
*/
int             ft_printf(char *str, ...)
{
    t_container list;
    va_start(list.ap, str);

    while (*str)
    {
        if (*str == '%')
        {
            parser(str, &list);
            str++;
            str++;
        }
        write(1, str, 1);
        str++;
    }
    va_end(list.ap);
    return (0);        
}


int     main(void)
{
    ft_printf("yelp %x t", 11);

    return(0);
}
