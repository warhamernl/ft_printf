/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 18:46:30 by mark           #+#    #+#                */
/*   Updated: 2019/09/17 19:39:15 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	num__len(int nb)
{
	int i;

	i = 0;
	if (nb < 0 || nb == 0)
		i = 1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}


void            check_lenthmod(char **str, t_container *list)
{
    if (**str == 'h')
    {
        (*str)++;
        if (**str == 'h')
        {
            list->lengthmod |= LEN_HH;
            (*str)++;
        }
        else
            list->lengthmod |= LEN_H;
    }
    else if (**str == 'l')
    {
        (*str)++;
        if ( **str  == 'l')
        {
            list->lengthmod |= LEN_LL;
            (*str)++;
        }
        else
            list->lengthmod |= LEN_L;
    }
    else if (**str == 'L')
    {
        (*str)++;
        list->lengthmod |= LEN_FL;
    }
}

void            check_widthprecision(char **str, t_container *list)
{
    while(**str == '*' ||( **str >= '0' && **str <= '9' )|| **str == '.')
    {
        if (**str == '*')
        {
            list->width = va_arg(list->ap, int);
            (*str)++;
        }
        if (**str >= '0' && **str <= '9')
        {
            list->width = ft_atoi(*str);
            (*str) += num__len(list->width);
            continue;
        }
        if (**str == '.')
        {
            (*str)++;
            if (**str == '*')
                list->precision = va_arg(list->ap, int);
            if (**str >= '0' && **str <= '9')
                list->precision = ft_atoi(*str);
            if (list->precision != -1)
            {
               (*str) += num__len(list->precision);
                continue;
            }
            if (list->precision == -1)
                list->precision = 0;
            if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd'|| **str == 'i'|| **str == 'o' || **str == 'x'|| **str == 'X' || **str == 'f' || **str == '%' || **str == 'u')
                return;
        }
        (*str)++;
    }
}

void            check_flag(char **str, t_container *list)
{
    while (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
    {   
        if (**str == '#')
            list->flags |= HASH;
        if (**str == '0')
            list->flags |= NUL;
        if (**str == '-')
            list->flags |= MIN;
        if (**str == ' ')
            list->flags |= SPACE;
        if (**str == '+')
            list->flags |= PLUS;
        (*str)++;
    }   

}
