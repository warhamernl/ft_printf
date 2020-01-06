/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 14:01:33 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/08 12:06:51 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *current;

	current = (t_list *)malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	if (!content)
	{
		current->content = NULL;
		current->content_size = 0;
	}
	else
	{
		current->content = (void *)malloc(content_size);
		if (!current->content)
		{
			free(current);
			return (NULL);
		}
		ft_memcpy(current->content, content, content_size);
		current->content_size = content_size;
	}
	current->next = NULL;
	return (current);
}
