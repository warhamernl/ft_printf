#include <stdio.h>
#include <unistd.h>
int main(void)
{
    size_t i;

    i = 0;
    char *s="law";
    i += write(1, s, 5);
    printf("\n%zu\n", i);
    return(0);
}