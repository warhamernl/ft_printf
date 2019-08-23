#include <stdio.h>

int main (void)
{   
    char strink[]="bla\0bla";
    printf("\0%s", strink);
}

/*  CHARS
width werkt.
- werkt met with
0 undefined maar werkt wel

 */