/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/11 20:45:47 by mark          ########   odam.nl         */
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

void        float_number(t_float_str *line, int length, long double number)
{
    if (number < 0)
    {
        line->str[line->length] = '-';
        line->length++;
    }
    if (length == 0)
    {
        line->str[line->length] = '0';
        line->length++;
    }
}

void    float_decimal(t_container *list, t_float_str *line, int length, long double number)
{
    long double remaining;

    remaining = number;
    while (line->length < length)
    {
        number *= 10;     
        line->str[line->length] = ft_itoa_base_float((int)number);
        decimal(number);
        line->length++;
    }
    line->str[line->length] = '.';
    line->length++;
    while (list->precision > 0)
    {
        remaining *= 10;
        line->str[line->length] = ft_itoa_base_float((int)remaining);
        decimal(remaining);
        line->length++;
        list->precision--;
    }

}


void        left_padding_float(t_container *list, char *str, t_whole_float *number, int length)
{
    int     store;
    t_float_str line;

    store = list->precision;
    line.length = 0;
    line.str = str;
    float_number(&line, length, number->number);
    float_decimal(list, &line, length, number->number);
    add_str(list, str);
    if (list->width > (store + 1 + length))
        add_space(list, (list->width - (store + 1 + length)));




}


void        right_padding_float(t_container *list, char *str, t_whole_float *number, int length)
{
    t_float_str line;

    line.str = str;
    line.length = 0;
    if (list->width > (list->precision + 1 + length))
        add_space(list, (list->width - (list->precision + 1 + length)));
    float_number(&line, length, number->number);
    float_decimal(list, &line, length, number->number);
    add_str(list, str);
}



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


void         f_float(t_container *list)
{ 
    t_whole_float number;
    char        *str;
    int length_wholenum;

    if (list->lengthmod & LEN_FL)
        number.number = va_arg(list->ap, long double);
    else
        number.number = (long double)va_arg(list->ap, double);
    if (list->precision == -1)
        list->precision = 6;
    number.remaining = decimal(number.remaining);
    length_wholenum = check_whole_number_double(&number.number);
    str = ft_strnew(length_wholenum + 1 + list->precision);
    if (list->flags & MIN)
        left_padding_float(list, str, &number, length_wholenum);
 //  else
 //       right_padding_float(list, str, &number, length_wholenum);
    free(str);
    return;


}