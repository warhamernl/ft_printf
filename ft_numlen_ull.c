/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_ull.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 22:40:20 by mark           #+#    #+#                */
/*   Updated: 2019/08/27 23:45:00 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlenll_ull(unsigned long long nb, int base, int nega)
{
	int i;

	i = 0 + nega;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}