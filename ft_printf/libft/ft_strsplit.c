/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:36:16 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/08 17:06:07 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**take_word(const char *s, char c, unsigned int words, char **split)
{
	int				word_length;
	unsigned int	word_n;
	int				i;

	word_n = 0;
	i = 0;
	while (s[i])
	{
		word_length = 0;
		while (s[i + word_length] != '\0' && s[i + word_length] != c)
			word_length++;
		if (word_length > 0)
		{
			split[word_n] = ft_strsub(s, i, (size_t)word_length);
			if (word_n < words)
				word_n++;
			i = word_length + i - 1;
		}
		i++;
	}
	split[word_n] = NULL;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**split;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = take_word(s, c, words, split);
	if (!split)
		return (NULL);
	return (split);
}
