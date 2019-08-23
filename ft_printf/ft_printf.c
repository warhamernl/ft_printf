/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/23 09:10:47 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

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

int             parser(char **str, t_container *list, t_buff *buff)
{
    t_desc  number;
    empty(list);
    (*str)++;
   if (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
       check_flag(&str, list);
   if  ((**str >= '0' && **str <= '9') || **str == '.' || **str == '*')
      check_widthprecision(&str, list);
   if (**str ==  'h' || **str == 'l' || **str == 'L')
        check_lenthmod(&str, list);   
    if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd'|| **str == 'i'|| **str == 'o' || **str == 'x'|| **str == 'X' || **str == 'f')
    {
        number = find_descriptor(**str);
        if (number == -1)
            return(-1);
        var_list[number](list, buff);
       (*str)++;
        return(0);
    }
    return (-1);
}

void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = -1;
    list->width = -1;
}

void            addbuff(t_buff *buff, char **c)
{
    buff->buff[buff->i] = **c;
    buff->i++;
    if (buff->i == BUFF_SIZE)
    {
        write(1, buff->buff, BUFF_SIZE -1);
        buff->i = 0;
    }
}

void            rrmaining(t_buff *buff)
{
    write(1, buff->buff, buff->i);
}

int             ft_printf(char *str, ...)
{
    t_container list;
    va_start(list.ap, str);
    va_copy(list.cpy, list.ap);
    t_buff buff;

    buff.i = 0;
    ft_memset(&buff, 0, BUFF_SIZE);
    while (*str)
    {
  //      printf("\n\n1 %s\n", buff.buff);
        if (*str == '%')
        {
            str += parser(&str, &list, &buff);
   //         printf("\n\n2 %s\n", buff.buff);
   //         str++;
        }
       
        
        addbuff(&buff, &str);
        str++;
  //      printf("\n\nchar %d\n", *str);
    }
 //   printf("\n\nEND %s\n", buff.buff);
    rrmaining(&buff);
    va_end(list.ap);
    return (0);        
}


int     main(void)
{
    ft_printf("yelp%-2c", 'x');

    return(0);
}
