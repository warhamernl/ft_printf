/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/09 02:07:44 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

char		*ft_itoa_base_float(t_number number)
{
	int store;
    char *str;

    str = ft_strnew(number.length);
	store = number.length;
	if (number.number == 0)
    {
        number.length = 1 + number.sign;
    }
	number.length += number.sign;
    if (number.sign == 1)
    {
        str[0] = '-';
    }
	while (number.sign != number.length)
	{
		str[number.sign] = ft_base(&(number.number), number.base, &store, 0);
		number.sign++;
//		store--;      
	}
	return (str);
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

void        left_padding_float(t_container *list, t_number number, double long i, int total_len)
{
    char *str;
    int  count;
    int d;

    d = 0;
    printf("%d\n", total_len);
    count = 0;
    str = ft_itoa_base_float(number);
    printf("%s\n", str);
    number.length++;
    str[number.length - 1] = '.';
    if (number.sign == 1)
        i = -i;
    while (count < list->precision)
    {
        d = 0;
        while (d < list->precision && d < 9)
        {
            count++;
            d++;
        }
        i *= ft_power(10, count);
        number.number = (unsigned long long)i;
        number.length = ft_numlen_ull(number.number, 10);
        str = ft_strjoin(str, ft_itoa_base_float(number));
        i = decimal(i);
    }
    add_str(list, str);
    free (str);
    if  (list->width > (number.sign + number.length + 1 + list->precision))
        add_space(list, (list->width - (number.sign + number.length + 1 + list->precision)));

}

void        right_padding_float(t_container *list, t_number number, double long i, int total_len)
{
    printf("%d %d %LF %d", list->precision, number.length, i, total_len);
}

void         f_float(t_container *list)
{ 
    long double i;
    long double  remaining;
    t_number number;
    int total_length;
    i = 0;
    remaining = 0.0;
    i = va_arg(list->ap, long double);
    printf("test %Lf\n",i); 
    printf("test %d\n",(int)i); 
  //  number.sign = check_sign_LD(&number, &i);
    number.base = 10 ;
    number.sign = 0;
    if (list->precision == -1)
        list->precision = 6;
    number.number = (unsigned long long)(int)i;
    if (list->lengthmod & LEN_FL)
        number.number = (unsigned long long)(int)(double)i;
    printf("%llu\n", number.number);
    number.length = ft_numlen_ull(number.number, number.base);
    total_length = look_max_len(*list, number);
    remaining = decimal(remaining);
    if (list->flags & MIN)
        left_padding_float(list, number, remaining, total_length);
   else
        right_padding_float(list, number, remaining, total_length);
    return;


}