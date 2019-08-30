/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_ull.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:44:44 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/29 22:15:15 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen_ull(unsigned long long nb, int base)
{
	int i;

	i = 0;
	if (nb == 0)
	{
		i = 1;
		return (i);
	}
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}