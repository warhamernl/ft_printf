/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/22 19:35:56 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

 
static const t_print_var var_list[12] = {
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
        f_percent,
        f_bits
                                    };

const t_pair  g_lookup_array[12] = {
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
 { 'b', E_BITS },
 };


void    pre_check_unsigned(char **str, t_container *list)
{
    (*str)++;
    if (ft_strchr("csidlxz", (int)**str) != NULL)
    {
        if (**str == 'c')
            list->bit = 2;
        else if (**str == 'i' || **str == 'd')
            list->bit = 4;
        else if (**str == 'l')
            list->bit = 8;
        else if (**str == SL)
            list->bit = 6;
        (*str)++;
    }
}


void    pre_check_binary(char **str, t_container *list)
{
    (*str)++;
    if (ft_strchr("csidlxzu", (int)**str) != NULL)
    {
        if (**str == 'c')
            list->bit = 1;
        else if (**str == 's')
            list->bit = 11;
        else if (**str == 'i' || **str == 'd')
            list->bit = 3;
        else if (**str == 'l')
            list->bit = 7;
        else if (**str == SL)
            list->bit = 5;
        else if (**str == 'u')
            pre_check_unsigned(str, list);
        (*str)++;
    }
}

 t_desc find_descriptor(char c)
 {
    t_pair pair;
    size_t i; 
    i = 0;
    size_t length = sizeof(g_lookup_array) / sizeof(t_pair);
    while (i < length)
    {
        pair = g_lookup_array[i];
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
    if (ft_strchr("cspdioxXf%ub", (int)**str) != NULL)
    {
        number = find_descriptor(**str);
        if (number == -1)
            return(-1);
        list->con = number;
        if (list->con == 11)
            pre_check_binary(str, list);
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
        if (*str == '{')
            str += handle_color(&list, ft_strdup(str));
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
    int a;

    a = 1;
    ft_printf("%bi", a);

    return (0);
}