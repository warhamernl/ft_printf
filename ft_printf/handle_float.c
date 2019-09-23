/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/23 19:51:24 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>


char	ft_base_float(unsigned long long *number, int *stored)
{
	int store;
	int temp;
	int con;
	char	*base_number;

	base_number="0123456789";
	store = *number / ft_power(10, (*stored - 1));
	temp = store % 10;
	con = base_number[temp];
	*number -= ft_power(10, *stored - 1) * temp;
	return (con);
}

void		ft_itoa_base_len_float(t_float_str *line, t_whole_float *wholenum, int length_wholenum, int side)
{
    unsigned long long temp;

    if (side == 1)
        temp = wholenum->remaining;
    else
        temp = wholenum->whole_num;
	if (wholenum->whole_num == 0)
		return;
	while (length_wholenum != 0)
	{
		line->str[line->length] = ft_base_float(&temp, &length_wholenum);
        line->length++;
        length_wholenum--;
	}
	return ;
}

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

void        rounding(t_float_str *line, int after_precision)
{
    int last_number;

	last_number = 0;
    if (after_precision >= 5)
    {
		line->length--;
		last_number = line->str[line->length] - '0';
        if (line->str[line->length] == '9')
        {
            while (line->str[line->length] == '9')
            {
                line->str[line->length] = '0';
                line->length--;
                if (line->str[line->length] == '.')
                    line->length--;
            }
            if (line->str[line->length] == '-' && line->str[line->length] == '+')
                line->str = ft_strjoin("1", line->str);
            else
            {
                line->str[line->length]++;
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

long double      decimal(long double remaining)
{
	remaining -= (unsigned long long)remaining;
    return (remaining);     
}

void        float_number(t_float_str *line, int *length, t_whole_float *number)
{
    if (number->sign == 1)
    {
        line->str[line->length] = '-';
        line->length++;
        length--;
    }
    if (*length == 0 && (int)number->whole_num == 0)
    {
        line->str[line->length] = '0';
        line->length++;
    }
}

void    float_decimal(t_container *list, t_float_str *line, int length_wholenum, t_whole_float *number)
{   
    ft_itoa_base_len_float(line, number, length_wholenum, 0);
    line->str[line->length] = '.';
    line->length++;
    while (list->precision > 0)
    {
        number->remaining *= 10;     
        ft_itoa_base_len_float(line, number, 1, 1);
        number->remaining = decimal(number->remaining);
        list->precision--;
    }
    number->remaining *= 10;
    rounding(line, (int)number->remaining);
}


void        left_padding_float(t_container *list, char *str, t_whole_float *number, int length_wholenum)
{
    int     store;
    t_float_str line;

    store = list->precision;
    line.length = 0;
    line.str = str;
    float_number(&line, &length_wholenum, number);
    float_decimal(list, &line, length_wholenum, number);
    add_str(list, str);
    if (list->width > (store + 1 + length_wholenum))
        add_space(list, (list->width - (store + 1 + length_wholenum)));
   free(str);



}


void        right_padding_float(t_container *list, char *str, t_whole_float *number, int length_wholenum)
{
    t_float_str line;

    line.str = str;
    line.length = 0;
    if (list->width > (list->precision + 1 + length_wholenum))
        add_space(list, (list->width - (list->precision + 1 + length_wholenum)));
    float_number(&line, &length_wholenum, number);
    float_decimal(list, &line, length_wholenum, number);
    add_str(list, str);
    free(str);
}



int         check_whole_number_double(long double decinum)
{
    int count;

    count = 0;
    if (decinum < (long double)1 && decinum > (long double )0)
        count = 1;
    if (decinum < 0.0L)
        count = 1;
    while (decinum > (long double)1)
    {
        decinum/= (long double)10;
        count++;
    }
    return (count);
}


void        into_def(t_whole_float *number, long double decinum, int *length_wholenum)
{
    if (decinum < 0.0L)
    {
        number->sign = 1;
        decinum = -decinum;
    }
    number->whole_num = (unsigned long long)decinum;
    *length_wholenum = check_whole_number_double(decinum);
    number->remaining = decimal(decinum);
}

void         f_float(t_container *list)
{ 
    t_whole_float number;
    char        *str;
    int length_wholenum;
    long double decinum;

    number.sign = 0;
    if (list->lengthmod & LEN_FL)
        decinum = va_arg(list->ap, long double);
    else
        decinum = (long double)va_arg(list->ap, double);
    if (list->precision == -1)
        list->precision = 6;
    if (nanfin(list, decinum) == 1)
        return ;
    into_def(&number, decinum, &length_wholenum);
    str = ft_strnew(length_wholenum + 1 + list->precision + number.sign);
    if (list->flags & MIN)
        left_padding_float(list, str, &number, length_wholenum);
   else
        right_padding_float(list, str, &number, length_wholenum);
}