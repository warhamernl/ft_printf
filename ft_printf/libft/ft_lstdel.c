/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:31:24 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/04/05 16:03:47 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nest;
	t_list *current;

	current = *alst;
	while (current)
	{
		nest = current->next;
		(*del)((current)->content, (current)->content_size);
		free(current);
		current = nest;
	}
	*alst = NULL;
}
