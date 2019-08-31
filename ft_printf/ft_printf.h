/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mark <mark@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:35:36 by mark           #+#    #+#                */
/*   Updated: 2019/08/31 22:25:07 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdio.h>//
# include <limits.h>

# define HASH (1 << 0)
# define NUL (1 << 1)
# define MIN (1 << 2)
# define PLUS (1 << 3)
# define SPACE (1 << 4)
# define LEN_H (1 << 0)
# define LEN_HH (1 << 1)
# define LEN_L	(1 << 2)
# define LEN_LL (1 << 3)
# define LEN_FL (1 << 4)
# define BUFF_SIZE 1024

typedef enum    e_desc {
 E_CHAR             = 0,
 E_STRING           = 1,
 E_VOID_POINTER     = 2,
 E_INT              = 3,
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
	int			flags;
	int			lengthmod;
	char 		buff[BUFF_SIZE];
	int			i;
	int			con;	
}				t_container;


typedef struct s_number
{
		unsigned long long number;
		int					sign;
		int					base;

}				t_number;

void            add_str(t_container *list,const char *str);
void        cast_itoa_pf_base(t_container *list, t_number *number);
void          right_padding_pf_base(t_container *list, t_number number, int length, int letter_case);
void          left_padding_pf_base(t_container *list, t_number number, int length, int letter_case);
void          check_flags(t_container *list, t_number number);
void     add_space(t_container *list, int amount);
void     add_zero(t_container *list, int amount);
void            addbuff(t_container *list, char c);
void    right_padding(char *str, t_container *list, int check);
void    left_padding(char *str, t_container *list, int check);
void         f_char(t_container *list);
void         f_float(t_container *list);
void         f_iint(t_container *list);
void         f_int(t_container *list);
void         f_void_pointer(t_container *list);
void         f_octal(t_container *list);
void         f_hex(t_container *list);
void         f_string(t_container *list);
void         f_uhex(t_container *list);
void            check_flag(char **str, t_container *list);
void            check_widthprecision(char **str, t_container *list);
void            check_lenthmod(char **str, t_container *list);
void            empty(t_container *list);
void		ft_itoa_base_len(t_container *list, t_number number, int length, int letter_case);
unsigned long long ft_power(int x, int power);
typedef	void	(*t_print_var)(t_container *list);

#endif