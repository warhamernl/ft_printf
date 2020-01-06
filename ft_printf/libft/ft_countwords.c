/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:40:48 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 17:42:59 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(const char *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s[0] != c)
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
