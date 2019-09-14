#include <stdio.h>
#include <limits.h>
#include <float.h>


int     main(void)
{
    long double i = 0.5L;
    long double d = 0.05L;
    
    

    if (d * 10.00L > i)
    {
        printf("ja\n");
        printf("%.1Lf\n", i);
        printf("%.1Lf\n", d);
    }
    else
    {
        printf("nee\n");
        printf("%.1Lf\n", i );
        printf("%.1Lf\n", d);
    }
    return (0);
}