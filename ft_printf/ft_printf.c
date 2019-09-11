/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/11 23:43:39 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "./ft_printf.h"
#include <unistd.h>

static     const t_print_var var_list[] = {
        f_char,
        f_string,
        f_void_pointer,
        f_int,
        f_int,
        f_octal,
        f_hex,
        f_uhex,
        f_float
                                    };


 t_pair g_lookup_array[] = {
 { 'c', E_CHAR },
 { 's', E_STRING },
 { 'p', E_VOID_POINTER },
 { 'i', E_INT },
 { 'd', E_INT },
 { 'o', E_OCTAL },
 { 'x', E_HEX },
 { 'X', E_UHEX },
 { 'f', E_FLOAT },
 };

 t_desc find_descriptor(char c)
 {
    size_t i; 
    i = 0;
    size_t length = sizeof(g_lookup_array) / sizeof(t_pair);
    while (i < length)
    {
        t_pair pair = g_lookup_array[i];
        if (c == pair.key)
        {
            return (pair.desc);
        }
        i++;
    }
    return (E_INVALID);
 }

int             parser(char **str, t_container *list)
{
    t_desc  number;
    empty(list);
    (*str)++;
   if (**str == '#' || **str == '0' || **str == '-' || **str == ' ' || **str == '+')
       check_flag(str, list);
   if  ((**str >= '0' && **str <= '9') || **str == '.' || **str == '*')
      check_widthprecision(str, list);
   if (**str ==  'h' || **str == 'l' || **str == 'L')
        check_lenthmod(str, list);   
    if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd'|| **str == 'i'|| **str == 'o' || **str == 'x'|| **str == 'X' || **str == 'f')
    {
        number = find_descriptor(**str);
        if (number == -1)
            return(-1);
        list->con = number;
        var_list[number](list);
       (*str)++;
        return(0);
    }
    return (0);
}

void            empty(t_container *list)
{
    list->lengthmod = 0;
    list->flags = 0;
    list->precision = -1;
    list->width = -1;
}

void            addbuff(t_container *list, char c)
{

        list->buff[list->i] = c;
        list->i++;
        if (list->i == BUFF_SIZE)
        {
            write(1, list->buff, BUFF_SIZE -1);
            ft_memset(list->buff, 0, BUFF_SIZE);
            list->i = 0;
        }

}

void            rrmaining(t_container list)
{
    write(1, list.buff, list.i);
}

int             ft_printf(char *str, ...)
{
    t_container list;
    va_start(list.ap, str);
    va_copy(list.cpy, list.ap);

    list.i = 0;
    ft_memset(list.buff, 0, BUFF_SIZE);
    while (*str)
    {
        if (*str == '%')
        {
            str += parser(&str, &list);
            continue;
        }      
        addbuff(&list, *str);
        str++;
    }
    rrmaining(list);
    va_end(list.ap);
    return (0);        
}


int			examples(void)
{
	int		a;
//	float	b;

	a = 255;
	//b = 2.718281828;
 /* 	printf("\nFlag summary: \n");
	printf("flag: none \neffect: print normally(right justify, space fill)\n");
	printf("flag: - \neffect: align left\n");
	printf("flag: + \neffect: print plus on positive numbers\n");
	printf("flag: 0 \neffect: zero fill\n");
	printf("flag: ' ' \neffect: space fill\n");
	printf("\nMinus padding: \n");
	printf("%-5d\n", a);
	printf("%-5d\n", -a);
	printf("%-5d\n", a * a);
	printf("%-5d\n", -a * a);
 	printf("\nPlus padding: \n");
	printf("%+5d\n", a);
	printf("%+5d\n", -a);
	printf("%+5d\n", a * a);
	printf("%+5d\n", -a * a);
	printf("\nPlus-Minus padding: \n");
	printf("%+-5d\n", a);
	printf("%+-5d\n", -a);
	printf("%+-5d\n", a * a);
	printf("%+-5d\n", -a * a);*/
	printf("\nZero padding: \n");
	printf("%05d\n", a);
	printf("%05d\n", -a);
	printf("%05d\n", a * a);
	printf("%05d\n", -a * a);
	printf("\nSpace padding: \n");
	printf("% 5d\n", a);
	printf("% 5d\n", -a);
	printf("% 5d\n", a * a);
	printf("% 5d\n", -a * a);
	printf("\nSpace-Zero padding: \n");
	printf("% 05d\n", a);
	printf("% 05d\n", -a);
	printf("% 05d\n", a * a);
	printf("% 05d\n", -a * a);
	printf("\nPlus-Zero padding: \n");
	printf("%+05d\n", a);
	printf("%+05d\n", -a);
	printf("%+05d\n", a * a);
	printf("%+05d\n", -a * a); 
 /*	printf("\nString padding:\n");
	printf("\nNo padding:\n");
	printf("%5s\n", "");
	printf("%5s\n", "a");
	printf("%5s\n", "ab");
	printf("%5s\n", "abcde");
	printf("\nMinus padding:\n");
	printf("b%-5s\n", "");
	printf("b%-5s\n", "a");
	printf("b%-5s\n", "ab");
	printf("b%-5s\n", "abcde");
	printf("\nFloat precision:\n");*/
/* 	printf("base %f\n", b);
	printf("(prec = 0) %.0f\n", b);
	printf("(prec = 1) %.1f\n", b);
	printf("(prec = 2) %.2f\n", b);
	printf("(prec = 6) %.6f\n", b);
	printf("(prec = 7) %.7f\n", b);
	printf("\nFloat width & precision:\n");
	printf("(prec = 0) %5.0f\n", b);
	printf("(prec = 1) %5.1f\n", b);
	printf("(prec = 2) %5.2f\n", b);
	printf("(prec = 6) %5.6f\n", b);
	printf("(prec = 7) %5.7f\n", b);
	printf("\nSeperate combineds:\n");
	printf("Float width, precision & minus:\n");
	printf("%-5.1f\n", b);
	printf("\nFloat width, precision & plus:\n");
	printf("%+5.1f\n", b);
	printf("\nFloat width, precision & zero:\n");
	printf("%05.1f\n", b);
	printf("\nFloat width, precision & plus-minus:\n");
	printf("%+-5.1f\n", b);
	printf("\nFloat width, precision & plus-zero:\n");
	printf("%+05.1f\n", b);
	printf("\nFloat width, precision & space-zero:\n");
	printf("% 05.1f\n", b);
	printf("\nFloat width, precision & minus-space:\n");
	printf("%- 5.1f\n", b);
	printf("\nHashtag padding:\n");
	printf("%#o\n", a);
//	printf("%#O\n", a);
	printf("%#x\n", a);
	printf("%#X\n", a);
	printf("\nHashtag float padding:\n");
	printf("%#f\n", b);
	printf("\nStd-Fin\n");*/
	return (0);
}

int			ft_examples(void)
{
	int		a;
//	float	b;

	a = 255;
//	b = 2.718281828;
/* 	ft_printf("\nFlag summary: \n");
	ft_printf("flag: none \neffect: print normally(right justify, space fill)\n");
	ft_printf("flag: - \neffect: align left\n");
	ft_printf("flag: + \neffect: print plus on positive numbers\n");
	ft_printf("flag: 0 \neffect: zero fill\n");
	ft_printf("flag: ' ' \neffect: space fill\n");
	ft_printf("\nMinus padding: \n");
	ft_printf("%-5d\n", a);
	ft_printf("%-5d\n", -a);
	ft_printf("%-5d\n", a * a);
	ft_printf("%-5d\n", -a * a);
 	ft_printf("\nPlus padding: \n");
	ft_printf("%+5d\n", a);
	ft_printf("%+5d\n", -a);
	ft_printf("%+5d\n", a * a);
	ft_printf("%+5d\n", -a * a);
	ft_printf("\nPlus-Minus padding: \n");
	ft_printf("%+-5d\n", a);
	ft_printf("%+-5d\n", -a);
	ft_printf("%+-5d\n", a * a);
	ft_printf("%+-5d\n", -a * a);*/
	ft_printf("\nZero padding: \n");
	ft_printf("%05d\n", a);
	ft_printf("%05d\n", -a);
	ft_printf("%05d\n", a * a);
	ft_printf("%05d\n", -a * a);
	ft_printf("\nSpace padding: \n");
	ft_printf("% 5d\n", a);
	ft_printf("% 5d\n", -a);
	ft_printf("% 5d\n", a * a);
	ft_printf("% 5d\n", -a * a);
	ft_printf("\nSpace-Zero padding: \n");
	ft_printf("% 05d\n", a);
	ft_printf("% 05d\n", -a);
	ft_printf("% 05d\n", a * a);
	ft_printf("% 05d\n", -a * a);
	ft_printf("\nPlus-Zero padding: \n");
	ft_printf("%+05d\n", a);
	ft_printf("%+05d\n", -a);
	ft_printf("%+05d\n", a * a);
	ft_printf("%+05d\n", -a * a);
/* 	ft_printf("\nString padding:\n");
	ft_printf("\nNo padding:\n");
	ft_printf("t%5s\n", "");
	ft_printf("t%5s\n", "a");
	ft_printf("t%5s\n", "ab");
	ft_printf("t%5s\n", "abcde");
	ft_printf("\nMinus padding:\n");
	ft_printf("t%-5s\n", "");//
	ft_printf("t%-5s\n", "a");//
	ft_printf("t%-5s\n", "ab");//
	ft_printf("t%-5s\n", "abcde");//*/
/* 	ft_printf("\nFloat precision:\n");
 	ft_printf("base %f\n", b);
	ft_printf("(prec = 0) %.0f\n", b);
	ft_printf("(prec = 1) %.1f\n", b);
	ft_printf("(prec = 2) %.2f\n", b);
	ft_printf("(prec = 6) %.6f\n", b);
	ft_printf("(prec = 7) %.7f\n", b);
	ft_printf("\nFloat width & precision:\n");
	ft_printf("(prec = 0) %5.0f\n", b);
	ft_printf("(prec = 1) %5.1f\n", b);
	ft_printf("(prec = 2) %5.2f\n", b);
	ft_printf("(prec = 6) %5.6f\n", b);
	ft_printf("(prec = 7) %5.7f\n", b);
	ft_printf("\nSeperate combineds:\n");
	ft_printf("Float width, precision & minus:\n");
	ft_printf("%-5.1f\n", b);
	ft_printf("\nFloat width, precision & plus:\n");
	ft_printf("%+5.1f\n", b);
	ft_printf("\nFloat width, precision & zero:\n");
	ft_printf("%05.1f\n", b);
	ft_printf("\nFloat width, precision & plus-minus:\n");
	ft_printf("%+-5.1f\n", b);
	ft_printf("\nFloat width, precision & plus-zero:\n");
	ft_printf("%+05.1f\n", b);
	ft_printf("\nFloat width, precision & space-zero:\n");
	ft_printf("% 05.1f\n", b);
	ft_printf("\nFloat width, precision & minus-space:\n");
	ft_printf("%- 5.1f\n", b);
	ft_printf("\nHashtag padding:\n"); //shift return down when ready
	ft_printf("%#o\n", a);
	ft_printf("%#x\n", a);
	ft_printf("%#X\n", a);
	ft_printf("\nHashtag float padding:\n");
	ft_printf("%#f\n", b); */
	ft_printf("\nft_Fin\n");
    return (0);
}

int		main(void)
{
	int x;

	x = examples();
	x = ft_examples();
	return (x);
}