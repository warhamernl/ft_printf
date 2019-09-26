#include <stdio.h>
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int 		main(void)
{
    printf("printf:		[%-#*.*o]\n", 0, 5, 0);
	ft_printf("ft_printf:	[%-#*.*o]\n", 0, 5, 0);
	return (0);
}