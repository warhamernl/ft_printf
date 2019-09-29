
#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <limits.h>
#include <stdio.h>


int		main(void)
{
    printf("printf:		[%-#*.*o]\n", 0, 0, 0);
	ft_printf("ft_printf:	[%-#*.*o]\n", 0, 0, 0);

	    printf("printf:		[%-#*.*o]\n", 5, 0, 0);
	ft_printf("ft_printf:	[%-#*.*o]\n", 5, 0, 0);

	    printf("printf:		[%-#*.*o]\n", 0, 5, 0);
	ft_printf("ft_printf:	[%-#*.*o]\n", 0, 5, 0);


  printf("printf:		[%-#*.*o]\n", 5, 5, 0);
	ft_printf("ft_printf:	[%-#*.*o]\n", 5, 5, 0);





}


