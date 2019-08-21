/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:35:36 by mark           #+#    #+#                */
/*   Updated: 2019/08/21 18:48:42 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

# define HASH (char)(1 << 0)
# define NUL (char)(1 << 1)
# define MIN (char)(1 << 2)
# define PLUS (char)(1 << 3)
# define SPACE (char)(1 << 4)
# define LEN_H (char)(1 << 0)
# define LEN_HH (char)(1 << 1)
# define LEN_L	(char)(1 << 2)
# define LEN_LL (char)(1 << 3)
# define LEN_FL (char)(1 << 4)


typedef enum    e_desc {
 E_CHAR             = 0,
 E_STRING           = 1,
 E_VOID_POINTER     = 2,
 E_INT              = 3,
 E_IINT             = 4,
 E_OCTAL            = 5,
 E_HEX              = 6,
 E_UHEX             = 7,
 E_FLOAT            = 8,
 E_INVALID          = -1
 }				t_desc;

 typedef struct  s_pair {
 char    key;
 t_desc  desc;
 }               t_pair;


 
typedef struct	s_container
{
	va_list		ap;
	va_list		cpy;
	int			width;
	int			precision;
	char		flags;
	char		lengthmod;

}				t_container;


/*
typedef struct	s_writer
{
	void	(*write)(struct s_writer *, char *, size_t);
	size_t	written;
	
}				t_writer;
*/

typedef struct s_number
{
		unsigned long long number;
		int					nega;
		int					base;

}				t_number;

void            check_flag(char **str, t_container *list);
void            check_widthprecision(char **str, t_container *list);
void            check_lenthmod(char **str, t_container *list);
void            empty(t_container *list);
size_t		*ft_itoa_base_len(char buff[128], t_number *number);
unsigned long long ft_power(int x, int power);
typedef	void	(*t_print_var)(t_container *list);

#endif