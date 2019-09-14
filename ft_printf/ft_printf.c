/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 14:06:17 by mlokhors       #+#    #+#                */
/*   Updated: 2019/09/14 15:48:30 by mark          ########   odam.nl         */
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


int main(void)
{
	/*
    ft_printf("TESTING PRINTF...\n(Note: the \"$\" serves to denote the end of output and is merely part of the test-file.)\n");
    // MISC
    ft_printf("\n---MISC---\n");
    ft_printf("Giving ft_printf two successive percentage signs(should output one):\n%%\n");
    // CHARS INTEGERS
    ft_printf("\n---CHAR INTEGERS---\n");
    ft_printf("ft_printf char:\n%hhd$\n", (char)123);
    printf("printf char:\n%hhd$\n", (char)123);
    ft_printf("ft_printf char with a space in front:\n% hhi$\n", (char)123);
    printf("printf char with a space in front:\n% hhi$\n", (char)123);
    ft_printf("ft_printf char with a + in front, if it's positive:\n%+hhi$\n", (char)123);
    printf("printf char with a + in front, if it's positive:\n%+hhi$\n", (char)123);
    ft_printf("ft_printf char with a + in front, if it's positive, with a space in front(should ignore space):\n%+hhi$\n", (char)123);
    printf("printf char with a + in front, if it's positive, with a space in front(should ignore space):\n%+hhi$\n", (char)123);
    ft_printf("ft_printf char with a precision of 2:\n%.2hhi$\n", (char)123);
    printf("printf char with a precision of 2:\n%.2hhi$\n", (char)123);
    ft_printf("ft_printf char with a minimum field width of 4:\n%4hhi$\n", (char)123);
    printf("printf char with a minimum field width of 4:\n%4hhi$\n", (char)123);
    ft_printf("ft_printf char with a minimum field width of 4, padded with zeroes:\n%04hhi$\n", (char)123);
    printf("printf char with a minimum field width of 4, padded with zeroes:\n%04hhi$\n", (char)123);
   // ft_printf("ft_printf char with a minimum field width of 4, padded with zeroes, with a precision of 2:\n%04.2hhi$\n", (char)123);
  //  printf("printf char with a minimum field width of 4, padded with zeroes, with a precision of 2:\n%04.2hhi$\n", (char)123);
    // INTEGERS
    ft_printf("\n---INTEGERS---\n");
    ft_printf("ft_printf int:\n%d$\n", 1435475);
    printf("printf int:\n%d$\n", 1435475);
    ft_printf("ft_printf int with a space in front:\n% i$\n", 1435475);
    printf("printf int with a space in front:\n% i$\n", 1435475);
    ft_printf("ft_printf int with a + in front, if it's positive:\n%+i$\n", 1435475);
    printf("printf int with a + in front, if it's positive:\n%+i$\n", 1435475);
    ft_printf("ft_printf int with a + in front, if it's positive, with a space in front(should ignore space):\n%+i$\n", 1435475);
    printf("printf int with a + in front, if it's positive, with a space in front(should ignore space):\n%+i$\n", 1435475);
    ft_printf("ft_printf int with a precision of 3:\n%.3i$\n", 1435475);
    printf("printf int with a precision of 3:\n%.3i$\n", 1435475);
    ft_printf("ft_printf int with a minimum field width of 20:\n%20i$\n", 1435475);
    printf("printf int with a minimum field width of 20:\n%20i$\n", 1435475);
    ft_printf("ft_printf int with a minimum field width of 20, padded with zeroes:\n%020i$\n", 1435475);
    printf("printf int with a minimum field width of 20, padded with zeroes:\n%020i$\n", 1435475);
  //  ft_printf("ft_printf int with a minimum field width of 20, padded with zeroes, with a precision of 3:\n%020.3i$\n", 1435475);
  //  printf("printf int with a minimum field width of 20, padded with zeroes, with a precision of 3:\n%020.3i$\n", 1435475);
	// LONG INTEGERS
    ft_printf("\n---LONG INTEGERS---\n");
    ft_printf("ft_printf long:\n%ld$\n", (long)LONG_MAX - 42);
    printf("printf long:\n%ld$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a space in front:\n% li$\n", (long)LONG_MAX - 42);
    printf("printf long with a space in front:\n% li$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a + in front, if it's positive:\n%+li$\n", (long)LONG_MAX - 42);
    printf("printf long with a + in front, if it's positive:\n%+li$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a + in front, if it's positive, with a space in front(should ignore space):\n%+li$\n", (long)LONG_MAX - 42);
    printf("printf long with a + in front, if it's positive, with a space in front(should ignore space):\n%+li$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a precision of 6:\n%.6li$\n", (long)LONG_MAX - 42);
    printf("printf long with a precision of 6:\n%.6li$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a minimum field width of 30:\n%30li$\n", (long)LONG_MAX - 42);
    printf("printf long with a minimum field width of 30:\n%30li$\n", (long)LONG_MAX - 42);
    ft_printf("ft_printf long with a minimum field width of 30, padded with zeroes:\n%030li$\n", (long)LONG_MAX - 42);
    printf("printf long with a minimum field width of 30, padded with zeroes:\n%030li$\n", (long)LONG_MAX - 42);
  //  ft_printf("ft_printf long with a minimum field width of 30, padded with zeroes, with a precision of 6:\n%030.6li$\n", (long)LONG_MAX - 42);
   // printf("printf long with a minimum field width of 30, padded with zeroes, with a precision of 6:\n%030.6li$\n", (long)LONG_MAX - 42);
	// LONG LONG INTEGERS
    ft_printf("\n---LONG LONG INTEGERS---\n");
    ft_printf("ft_printf long long:\n%lld$\n", (long long)LLONG_MAX - 42);
    printf("printf long long:\n%lld$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a space in front:\n% lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a space in front:\n% lli$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a + in front, if it's positive:\n%+lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a + in front, if it's positive:\n%+lli$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a + in front, if it's positive, with a space in front(should ignore space):\n%+lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a + in front, if it's positive, with a space in front(should ignore space):\n%+lli$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a precision of 6:\n%.6lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a precision of 6:\n%.6lli$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a minimum field width of 40:\n%40lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a minimum field width of 40:\n%40lli$\n", (long long)LLONG_MAX - 42);
    ft_printf("ft_printf long long with a minimum field width of 40, padded with zeroes:\n%040lli$\n", (long long)LLONG_MAX - 42);
    printf("printf long long with a minimum field width of 40, padded with zeroes:\n%040lli$\n", (long long)LLONG_MAX - 42);
  //  ft_printf("ft_printf long long with a minimum field width of 40, padded with zeroes, with a precision of 6:\n%040.6lli$\n", (long long)LLONG_MAX - 42);
   // printf("printf long long with a minimum field width of 40, padded with zeroes, with a precision of 6:\n%040.6lli$\n", (long long)LLONG_MAX - 42);
	// SHORT INTEGERS
    ft_printf("\n---SHORT INTEGERS---\n");
    ft_printf("ft_printf short:\n%hd$\n", (short int)1023);
    printf("printf short:\n%hd$\n", (short int)1023);
    ft_printf("ft_printf short with a space in front:\n% hi$\n", (short int)1023);
    printf("printf short with a space in front:\n% hi$\n", (short int)1023);
    ft_printf("ft_printf short with a + in front, if it's positive:\n%+hi$\n", (short int)1023);
    printf("printf short with a + in front, if it's positive:\n%+hi$\n", (short int)1023);
    ft_printf("ft_printf short with a + in front, if it's positive, with a space in front(should ignore space):\n%+hi$\n", (short int)1023);
    printf("printf short with a + in front, if it's positive, with a space in front(should ignore space):\n%+hi$\n", (short int)1023);
    ft_printf("ft_printf short with a precision of 2:\n%.2hi$\n", (short int)1023);
    printf("printf short with a precision of 2:\n%.2hi$\n", (short int)1023);
    ft_printf("ft_printf short with a minimum field width of 8:\n%8hi$\n", (short int)1023);
    printf("printf short with a minimum field width of 8:\n%8hi$\n", (short int)1023);
    ft_printf("ft_printf short with a minimum field width of 8, padded with zeroes:\n%08hi$\n", (short int)1023);
    printf("printf short with a minimum field width of 8, padded with zeroes:\n%08hi$\n", (short int)1023);
  //  ft_printf("ft_printf short with a minimum field width of 8, padded with zeroes, with a precision of 2:\n%08.2hi$\n", (short int)1023);
  //  printf("printf short with a minimum field width of 8, padded with zeroes, with a precision of 2:\n%08.2hi$\n", (short int)1023);
    // STRINGS
    ft_printf("\n---STRINGS---\n");
    ft_printf("ft_printf string:\n%s$\n", "For the people!");
    printf("printf string:\n%s$\n", "For the people!");
    ft_printf("ft_printf string with a minimum field width of 20:\n%20s$\n", "For the people!");
    printf("printf string with a minimum field width of 20:\n%20s$\n", "For the people!");
    ft_printf("ft_printf string with a minimum field width of 20, padded on the right:\n%-20s$\n", "For the people!");
    printf("printf string with a minimum field width of 20, padded on the right:\n%-20s$\n", "For the people!");
    ft_printf("ft_printf string with a minimum field width of 20 to the right, with a precision of 10:\n%-20.10s$\n", "For the people!");
    printf("printf string with a minimum field width of 20 to the right, with a precision of 10:\n%-20.10s$\n", "For the people!");
    // FLOATS */
    ft_printf("\n---FLOATS---\n");
    ft_printf("ft_printf float:\n%f\n", 1.67);
    printf("printf float:\n%f\n", 1.67);
    ft_printf("ft_printf float:\n%f\n", 1.5);
    printf("printf float:\n%f\n", 1.5);

    return (0);
}