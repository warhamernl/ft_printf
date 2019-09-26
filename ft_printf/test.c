#include <stdio.h>
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int 		main(void)
{
    printf("printf:		[%-20.10f]\n", (double)-((double)10 / 3));
	ft_printf("ft_printf:	[%-20.10f]\n", (double)-((double)10 / 3));

}