/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/21 20:31:24 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

 
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
   if (ft_strchr("#0- +", (int)**str) != NULL)
       check_flag(str, list);
   if  (ft_strchr("0123456789.*", (int)**str) != NULL)
      check_widthprecision(str, list);
   if (ft_strchr("hlL", (int)**str) != NULL)
        check_lenthmod(str, list);   
    if (ft_strchr("cspdioxXf%u", (int)**str) != NULL)
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