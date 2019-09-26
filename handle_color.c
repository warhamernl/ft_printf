/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/22 13:51:55 by mark           #+#    #+#                */
/*   Updated: 2019/09/25 18:26:47 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_bcolor(t_container *list, int number, int length)
{
	char *colors[7];

	colors[0] = BRED;
	colors[1] = BGREEN;
	colors[2] = BYELLOW;
	colors[3] = BLUE;
	colors[4] = BBLUE;
	colors[5] = BMAGENTA;
	colors[6] = BCYAN;
	if (length > 6)
		return (0);
	add_str(list, colors[number]);
	return (length);
}

int			check_color(t_container *list, int number, int length)
{
	char *colors[6];

	colors[0] = RED;
	colors[1] = GREEN;
	colors[2] = YELLOW;
	colors[3] = MAGENTA;
	colors[4] = CYAN;
	colors[5] = RESET;
	if (length > 6)
		return (0);
	add_str(list, colors[number]);
	return (length);
}

int			handle_b_blue(t_container *list, char *str)
{
	if (ft_strncmp(str, "{BRED}", 6) == 0)
		return (check_bcolor(list, 0, 6));
	else if (ft_strncmp(str, "{BGREEN}", 8) == 0)
		return (check_bcolor(list, 1, 8));
	else if (ft_strncmp(str, "{BYELLOW}", 9) == 0)
		return (check_bcolor(list, 2, 9));
	else if (ft_strncmp(str, "{BLUE}", 6) == 0)
		return (check_bcolor(list, 3, 6));
	else if (ft_strncmp(str, "{BBLUE}", 7) == 0)
		return (check_bcolor(list, 4, 7));
	else if (ft_strncmp(str, "{BMAGENTA}", 9) == 0)
		return (check_bcolor(list, 5, 9));
	else if (ft_strncmp(str, "{BCYAN}", 7) == 0)
		return (check_bcolor(list, 6, 7));
	return (0);
}

int			handle_color(t_container *list, char *str)
{
	if (ft_strncmp(str, "{RED}", 5) == 0)
		return (check_color(list, 0, 5));
	else if (ft_strncmp(str, "{GREEN}", 7) == 0)
		return (check_color(list, 1, 7));
	else if (ft_strncmp(str, "{YELLOW}", 8) == 0)
		return (check_color(list, 2, 8));
	else if (ft_strncmp(str, "{MAGENTA}", 9) == 0)
		return (check_color(list, 3, 9));
	else if (ft_strncmp(str, "{CYAN}", 6) == 0)
		return (check_color(list, 4, 6));
	else if (ft_strncmp(str, "{RESET}", 7) == 0)
		return (check_color(list, 5, 7));
	else
		return (handle_b_blue(list, str));
}
