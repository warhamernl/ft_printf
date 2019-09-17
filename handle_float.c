/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/17 13:30:46 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>


int check_nanfinright(t_container *list, long double number)
{
    if (number != number)
    {
        add_space(list, list->width - 3);
        add_str(list, "nan");
        return (1);
    }
    if (number == 1.0L /0.0L)
    {
         add_space(list, list->width - 3);
        add_str(list, "inf");
        return (1);
    }
    if (number  == -1.0/0.0L)
    {
        add_space(list, list->width - 4);
        add_str(list, "-inf");
        return (1);
    }
    return (0);
}

int check_nanfinleft(t_container *list, long double number)
{
    if (number != number)
    {
        add_str(list, "nan");
        add_space(list, list->width - 3);
        return (1);
    }
    if (number == 1.0L /0.0L)
    {
        add_str(list, "inf");
        add_space(list, list->width - 3);
        return (1);
    }
    if (number  == -1.0/0.0L)
    {
        add_str(list, "-inf");
        add_space(list, list->width - 4);
        return (1);
    }
    return (0);
}


int        nanfin(t_container *list, long double number)
{
    if (check_nanfinleft(list, number) == 1 && list->flags & MIN)
        return (1);
    if (check_nanfinright(list, number) == 1)
        return (1);
    return (0);
}

void        rounding(t_float_str *line,int remaining)
{
    int last_number;
    char *tmp;

    line->length--;
    tmp = 0;
    last_number = ft_atoi(&line->str[line->length]);
    if (remaining > 0.5L && last_number % 2 == 0)
    {
        if (line->str[line->length] == '9')
        {
            printf("test2\n");
            while (line->str[line->length] == '9')
            {
                line->str[line->length] = '0';
                line->length--;
                if (line->str[line->length] == '.')
                    line->length--;
            }
            if (line->str[0] != '-' && line->str[0] != '+')
                line->str = ft_strjoin("1", line->str);
            else
            {
                tmp = ft_strjoin(&line->str[line->length], "1");
                line->str = ft_strjoin(tmp, line->str);
            }
        }
        else
        {
            if (line->str[line->length] == '.')
                line->length--;
            line->str[line->length]++;
        }   
    }
}


char		ft_itoa_base_float(int number)
{
    char	*base_number;
    char c;

    base_number ="0123456789";
    c = base_number[number];     
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
    while (remaining > 1.00L)
        remaining /= (long double)10;
    return (remaining);    
    /* 
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
    return (remaining);*/
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

void    float_decimal(t_container *list, t_float_str *line, int length, t_whole_float *number)
{
    while (line->length < length)
    {
        number->number *= 10;     
        line->str[line->length] = ft_itoa_base_float((int)number->number);
        decimal(number->number);
        line->length++;
    }
    line->str[line->length] = '.';
    line->length++;
    while (list->precision > 0)
    {
        number->remaining *= 10;
        line->str[line->length] = ft_itoa_base_float((int)number->remaining);
        number->remaining = decimal(number->remaining);
        line->length++;
        list->precision--;
    }
    number->remaining *= 10;
    rounding(line, (int)number->remaining);
}


void        left_padding_float(t_container *list, char *str, t_whole_float *number, int length)
{
    int     store;
    t_float_str line;

    store = list->precision;
    line.length = 0;
    line.str = str;
    float_number(&line, length, number->number);
    float_decimal(list, &line, length, number);
    add_str(list, str);
    if (list->width > (store + 1 + length))
        add_space(list, (list->width - (store + 1 + length)));
    free(str);



}


void        right_padding_float(t_container *list, char *str, t_whole_float *number, int length)
{
    t_float_str line;

    line.str = str;
    line.length = 0;
    if (list->width > (list->precision + 1 + length))
        add_space(list, (list->width - (list->precision + 1 + length)));
    float_number(&line, length, number->number);
    float_decimal(list, &line, length, number);
    add_str(list, str);
    free(str);
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
    if (nanfin(list, number.number) == 1)
        return;
    number.remaining = decimal(number.number);
    length_wholenum = check_whole_number_double(&number.number);
    str = ft_strnew(length_wholenum + 1 + list->precision);
    if (list->flags & MIN)
        left_padding_float(list, str, &number, length_wholenum);
   else
        right_padding_float(list, str, &number, length_wholenum);
    
    return;


}