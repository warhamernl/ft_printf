/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:25:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/23 13:30:48 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         f_float(t_container *list)
{
    printf("%d\n", list->width);
    printf("%d\n", list->i);
    return;
}