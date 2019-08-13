#include <stdio.h>
#include <unistd.h>
int main(void)
{
    char str[]= "ab";
    printf("%ld", sizeof(str));
}