/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/20 16:14:29 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "./ft_printf.h"
#include <unistd.h>

 
void         f_percent(t_container *list)
{
    if (list->flags & MIN)
    {
        if (list->width != -1)
        {
            addbuff(list, '%');
            add_space(list, list->width - 1);
        }
        else
            addbuff(list, '%');
    }
    else
    {
        if (list->width != -1)
        {
            if (list->flags & NUL)
                add_zero(list, list->width - 1);
            else
                add_space(list, list->width - 1);
            addbuff(list, '%');
        }
        else
            addbuff(list, '%');
    }
}


static     const t_print_var var_list[11] = {
        f_char,
        f_string,
        f_void_pointer,
        f_int,
        f_int,
        f_octal,
        f_hex,
        f_uhex,
        f_float,
        f_uint,
        f_percent
                                    };

const t_pair  g_lookup_array[11] = {
 { 'c', E_CHAR },
 { 's', E_STRING },
 { 'p', E_VOID_POINTER },
 { 'i', E_INT },
 { 'd', E_INT },
 { 'o', E_OCTAL },
 { 'x', E_HEX },
 { 'X', E_UHEX },
 { 'f', E_FLOAT },
 { 'u', E_UINT},
 { '%', E_PERCENT },
 };

 t_desc find_descriptor(char c)
 {
    size_t i; 
    i = 0;
    size_t length = sizeof(g_lookup_array) / sizeof(t_pair);
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

int             parser(char **str, t_container *list)
{
    t_desc  number;
    empty(list);
    (*str)++;
   if (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
       check_flag(str, list);
   if  ((**str >= '0' && **str <= '9') || **str == '.' || **str == '*')
      check_widthprecision(str, list);
   if (**str ==  'h' || **str == 'l' || **str == 'L')
        check_lenthmod(str, list);   
    if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd'|| **str == 'i'|| **str == 'o' || **str == 'x'|| **str == 'X' || **str == 'f' || **str == '%' || **str == 'u')
    {
        number = find_descriptor(**str);
        if (number == -1)
            return(-1);
        list->con = number;
        var_list[number](list);
       (*str)++;
        return(0);
    }
    return (0);
}

void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = -1;
    list->width = -1;
}

void            addbuff(t_container *list, char c)
{

        list->buff[list->i] = c;
        list->i++;
        if (list->i == BUFF_SIZE)
        {
            write(1, list->buff, BUFF_SIZE -1);
            ft_memset(list->buff, 0, BUFF_SIZE);
            list->i = 0;
        }

}

void            rrmaining(t_container list)
{
    write(1, list.buff, list.i);
}

int             ft_printf(char *str, ...)
{
    t_container list;
    va_start(list.ap, str);

    list.i = 0;
    ft_memset(list.buff, 0, BUFF_SIZE);
    while (*str)
    {
        if (*str == '%')
        {
            str += parser(&str, &list);
            continue;
        }      
        addbuff(&list, *str);
        str++;
    }
    rrmaining(list);
    va_end(list.ap);
    return (list.i);        
}


int     main(void)
{
    ft_printf("{%f}", -1.42);


    return (0);
}