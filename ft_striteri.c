/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 20:01:43 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/06 21:31:38 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (!f || !s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
