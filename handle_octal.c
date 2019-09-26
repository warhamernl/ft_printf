/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_octal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:23:49 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/26 18:34:56 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_itoa_pf_base(t_container *list, t_number *number)
{
	if (list->lengthmod == 0)
		number->number = (unsigned long long)(unsigned int)number->number;
	else if (list->lengthmod & LEN_H)
		number->number = (unsigned long long)(unsigned short int)number->number;
	else if (list->lengthmod & LEN_HH)
		number->number = (unsigned long long)(unsigned char)number->number;
	else if (list->lengthmod & LEN_L)
		number->number = (unsigned long long)(unsigned long int)number->number;
	else if (list->lengthmod & LEN_LL)
		number->number = (unsigned long long)number->number;
}

void	right_padding_pf_base(t_container *list,
			t_number number, int letter_case)
{
	int amount;

	amount = get_amount_pf(list, number);
	check_width_pf(list, number);

	if (list->flags & NUL)
		right_padding_pre_zero(list, number);
	else
	{
		if (list->width > amount && !(list->flags & NUL))
			add_space(list, list->width - amount);
		check_flags(list, number);
	}
	if (!(number.number == 0 && list->precision == 0) ||
		(list->con == 5 && list->flags & HASH &&
			number.number == 0 && list->precision == 0))
		pre_itoa_pf_padding(list, number, letter_case);
}

int		o_check_zero_left(t_container *list)
{
	int check;

	check  = 0;
	if (list->width == -1)
		list->width = 0;
	if (list->precision == -1)
		list->precision = 0;
	if (list->flags & HASH)
	{
		check = 1;
		addbuff(list, '0');
	}
	if (list->precision > 0)
		add_zero(list, list->precision);
	if (list->width > (list->precision + check) && list->width > 0)
		add_space(list, list->width - list->precision - check);
	return (1);
}

int		o_check_zero_right(t_container *list)
{
	int		check;

	check = 0;
	if (list->flags & HASH)
		check = 1;
	if (list->width == -1)
		list->width = 0;
	if (list->precision == -1)
		list->precision = 0;
	if (list->width > (list->precision + check) && list->width > 0)
		add_space(list, list->width - list->precision - check);
	if (check == 1)
		addbuff(list, '0');
	if (list->precision > 0)
		add_zero(list, list->precision);
	return (1);
}

int		o_check_zero(t_container *list, t_number number)
{
	if (list->width == -1 && list->precision == -1 && number.number == 0)
	{
		addbuff(list, '0');
		return (1);
	}
	if (list->width == 0 && list->precision == 0 && number.number == 0)
	{
		if (list->flags & HASH)
			addbuff(list, '0');
		return (1);
	}
	if (list->flags & HASH)
		list->precision--;
	if (list->flags & MIN && number.number == 0)
		return (o_check_zero_left(list));
	else
		return (o_check_zero_right(list));
	return (0);
}

void	left_padding_pf_base(t_container *list,
			t_number number, int letter_case)
{
	int amount;

	amount = get_amount_pf(list, number);
	check_width_pf(list, number);
	check_flags(list, number);
	if (list->width == 0 && list->precision == 0 && number.number == 0)
		return ;
	if (!(number.number == 0 && list->precision == 0) ||
		(list->con == 5 && list->flags & HASH &&
			number.number == 0 && list->precision == 0))
		pre_itoa_pf_padding(list, number, letter_case);
	if (list->width > amount)
		add_space(list, list->width - amount);
}

void	f_octal(t_container *list)
{
	unsigned long long	i;
	t_number			number;

	i = va_arg(list->ap, unsigned long long);
	number.sign = 0;
	number.base = 8;
	number.number = i;
	if ((list->flags & NUL && list->flags & MIN) ||
		(list->precision != -1))
		list->flags &= ~(NUL);
	cast_itoa_pf_base(list, &number);
	number.length = ft_numlen_ull(number.number, number.base);
	if (number.number == 0) 
	{
		if (o_check_zero(list, number) == 1)
			return;
	}
	if (list->flags & MIN)
		left_padding_pf_base(list, number, 0);
	else
		right_padding_pf_base(list, number, 0);
	return ;
}
