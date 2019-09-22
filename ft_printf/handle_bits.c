/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_bits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/22 17:07:18 by mark           #+#    #+#                */
/*   Updated: 2019/09/22 21:24:11 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     bits_max(t_container *list, int *space_count)
{
    if (list->bit == 1 || list-> bit == 2)
    {
        *space_count = 0;
        return (8);
    }
    if (list->bit == 3 || list-> bit == 4)
    {
        *space_count = 3;
        return (32);
    }
    if (list->bit == 5 || list-> bit == 6)
    {
        *space_count = 1;
        return (16);
    }
    if (list->bit == 7 || list-> bit == 8)
    {
        *space_count = 7;
        return (64);
    }
    return (0);
}

void print_bits(t_container *list, t_bits sort)
{
    int max;
    int i;
    int space_count;
    i = 0;
    max = bits_max(list, &space_count);
    while (i < max)
    {  
        if (sort.b & (1 << (max - 1 - i)))
            addbuff(list, '1');
        else
            addbuff(list, '0');
        if ((i + 1) % 8 == 0 && space_count != 0)
        {
            addbuff(list, ' ');
            space_count--;
        }
        i++;
    }
    return;
}
/*

void              long_get_data(t_container *list, t_bits *sort)
{
    if (list->bit == 6 || list->bit == 7)
    {
        if (list->bit == 2)
            sort->c = va_arg(list->ap, long);
        else
            sort->d = va_arg(list->ap, unsigned long);
    }
    return ;

}
*/

void             get_data(t_container *list, t_bits *sort)
{
    if (list->bit == 1 || list->bit == 2)
    {
        if (list->bit == 1)
            sort->a = (int)(char)va_arg(list->ap, int);
        else
            sort->b = (int)(unsigned char)va_arg(list->ap, unsigned int);
    }
    else if (list->bit == 3 || list->bit == 4)
    {
        if (list->bit == 3)
            sort->a = va_arg(list->ap, int);
        else
            sort->b = va_arg(list->ap, unsigned int);
    }
    else if (list->bit == 4 || list->bit == 5)
    {
        if (list->bit == 4)
            sort->a = (int)(short)va_arg(list->ap, int);
        else
            sort->b = (int)(unsigned short)va_arg(list->ap, unsigned int);
    }
    
    return ;
}


void      f_bits(t_container *list)
{
    t_bits sort;

 //   if (list->bit == 11 || list->bit == 9 || list->bit == 7 || list->bit == 5)
  //      long_get_data(list, &sort);
 //   else
        get_data(list, &sort);
    if (list->bit != 0 && list->bit != 12)
        print_bits(list, sort);
 //   else if (list->bit == 12)
  //      print_bits_str(list);
    return;
}