/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/09 17:54:00 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

char	ft_base_f(int n, int base)
{
	int temp;
	int con;
	char	*base_number;

	base_number ="0123456789";
	temp = n % base;
	con = base_number[temp];

	return (con);
}

char		ft_itoa_base_float(int number)
{

    char c;

    c = ft_base_f(number, 10);     
	return (c);
}



int look_max_len(t_container list, t_number number)
{
    if (list.width > (number.sign + number.length + 1 + list.precision))
        return (list.width);
    else
        return (number.sign + number.length + 1 + list.precision);
    
}
/*
int         check_sign_LD(t_number *number, long double *i)
{
    if (*i < 0)
    {
        number->sign = 1;
        return (1);
    }
    return (0);
}
*/

long double      decimal(long double remaining)
{
    while (remaining >= (long double)1000000.00)
        remaining -= (long double)1000000.00;    
    while (remaining >= (long double)10000.00)
        remaining -= (long double)10000.00;
    while (remaining >= (long double)1000.00)
        remaining -= (long double)1000.00;
    while (remaining >= (long double)100.00)
        remaining -= (long double)100.00;
    while (remaining >= (long double)10.00)
        remaining -= (long double)10.00;
    while (remaining >= (long double)1.00)
        remaining -= (long double)1.00;
    return (remaining);
}

void        left_padding_float(t_container *list, char *str, double long number, double long remaining, int length)
{
    double remaning;
    int     i;

    i = 0;
    remaning = number;
    if (number < 0)
    {
        str[i] = '-';
        i++;
    }
    if (length == 0)
    {
        str[i] = '0';
        i++;
    }
    while (i < length)
    {
        number *= 10;
        
        str[i] = ft_itoa_base_float((int)number);
        decimal(number);
        i++;
    }
    str[i] = '.';
    i++;
    while (list->precision > 0)
    {
        remaining *= 10;
        str[i] = ft_itoa_base_float((int)remaining);
        decimal(remaining);
        i++;
        list->precision--;
    }
    add_str(list, str);
    if (list->width > (list->precision + 1 + length))
        add_space(list, (list->width - (list->precision + 1 + length)));




}

/* 
void        right_padding_float(t_container *list, t_number number, double long i, int total_len)
{
    printf("%d %d %LF %d", list->precision, number.length, i, total_len);
}

char  strack_str(t_container *list, int length)
{

}
*/
int         check_whole_number_double(long double *i)
{
    int count;

    count = 0;
    if (i < (long double*)1 && i > (long double *)0)
        count = 1;
    if (*i < 0.0L)
        count = 1;
    while (*i > (long double)1)
    {
        *i /= (long double)10;
        count++;
    }
    return (count);
}
/*
char *get_string(t_container *list, int length)
{
    char str[length + list->precision + 2];
    ft_memset(str, 0, length + list->precision + 2);
    return (str);
}
*/

void         f_float(t_container *list)
{ 
    long double remaining;
    long double number;
    char        *str;
    int length_wholenum;

    if (list->lengthmod & LEN_FL)
        number = va_arg(list->ap, long double);
    else
        number = (long double)va_arg(list->ap, double);
    if (list->precision == -1)
        list->precision = 6;
    remaining = number;
    remaining = decimal(remaining);
    length_wholenum = check_whole_number_double(&number);
    str = ft_strnew(length_wholenum + 1 + list->precision);
    if (list->flags & MIN)
        left_padding_float(list, str, number, remaining, length_wholenum);
   else
//        right_padding_float(list, str, number, remaining);
    free(str);
    return;


}