#include <limits.h>
#include <stdio.h>
#include <float.h>

int     main(void)
{
    long double i;
    i = 0.0;

    printf("blabla%#6.2Lf", 1 / i);
}