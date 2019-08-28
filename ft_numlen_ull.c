/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_ull.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:44:44 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/28 15:45:53 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen_ull(unsigned long long nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}