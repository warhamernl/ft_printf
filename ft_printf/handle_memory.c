/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_memory.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:14 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/31 00:37:45 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int		ft_atoi_uc(const unsigned char *str)
{
	int		nega;
	long	result;

	nega = 1;
	result = 0;
	while (ft_isspace((int)*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			nega = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (nega * result);
}
*/

void         f_void_pointer(t_container *list)
{
    void *pointer;
  //  int     mem_adress;
    t_number number;
    int length;
    char *str;

    str ="0x";
    add_str(list, str);
    pointer = va_arg(list->ap, void *);
 //   mem_adress = ft_atoi_uc((unsigned char *)pointer);
    number.number = (unsigned long long)pointer;
    number.sign = 0;
    number.base = 16;
    length = ft_numlen_ull(number.number, number.base);
    ft_itoa_base_len(list, number, length, 0);

    return;
}