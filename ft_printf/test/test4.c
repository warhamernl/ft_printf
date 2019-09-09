#include <stdio.h>
#include <limits.h>
#include <float.h>


int         check_whole_number_double(long double i)
{
    int d;

    d = 0;
    while (i > (long double)1)
    {
        i /= (long double)10;
        printf("%.50Lf\n", i);
        d++;
    }
    return (d);
}


int main (void)
{
    long double i = 154654643534535756756756.00;
    printf("\n%Lf\n", i);
    printf("\n\n%d\n\n", check_whole_number_double(i));

        printf("FLT_MAX = %g\n", FLT_MAX);
    printf("DBL_MAX = %g\n", DBL_MAX);
    printf("LDBL_MAX = %Lg\n", LDBL_MAX);
}

/*  CHARS
width werkt.
- werkt met with
0 undefined maar werkt wel

 */