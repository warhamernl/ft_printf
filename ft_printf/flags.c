/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 18:46:30 by mark           #+#    #+#                */
/*   Updated: 2019/08/23 09:20:23 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	num__len(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		i = 1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}


void            check_lenthmod(char ***str, t_container *list)
{
    if (***str == 'h')
    {
        if (***str + 1 == 'h')
        {
            list->lengthmod = LEN_H;
            (**str)++;
        }
        else
            list->lengthmod = LEN_HH;
    }
    else if (***str == 'l')
    {
        if ( ***str + 1 == 'l')
        {
            list->lengthmod = LEN_L;
            (**str)++;
        }
        else
            list->lengthmod = LEN_LL;
    }
    else if (***str == 'L')
    {
            list->lengthmod = LEN_FL;
    }
    (**str)++;
}

void            check_widthprecision(char ***str, t_container *list)
{
    while(***str == '*' ||( ***str >= '0' && ***str <= '9' )|| ***str == '.')
    {
        if (***str == '*')
            list->width = va_arg(list->ap, int);
        if (***str >= '0' && ***str <= '9')
        {
            list->width = ft_atoi(**str);
            (**str) += num__len(list->width);
            continue;
        }
        if (***str == '.')
        {
            (**str)++;
            if (***str == '*')
                list->precision = va_arg(list->ap, int);
            if (***str >= '0' && ***str <= '9')
                list->precision = ft_atoi(**str);
        }
        (**str)++;
    }
}

void            check_flag(char ***str, t_container *list)
{
    while (***str == '#' || ***str == '0' || ***str == '-' || ***str == ' ' || ***str == '+')
    {   
        if (***str == '#')
            list->flags |= HASH;
        if (***str == '0')
            list->flags |= NUL;
        if (***str == '-')
            list->flags |= MIN;
        if (***str == ' ')
            list->flags |= SPACE;
        if (***str == '+')
            list->flags |= PLUS;
        (**str)++;
    }   

}
