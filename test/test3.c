#include <stdio.h>
#include <unistd.h>
typedef union {
  double f;
  struct {
    unsigned long int mantisa : 52;
    unsigned long int exponent : 11;
    unsigned long int sign : 1;
  } parts;
} float_cast;

int main(void) {

  __float128 i;
  float_cast d1 = { .f = 2 };

  printf("sign = %lu\n", d1.parts.sign);
  printf("exponent = %lu\n", d1.parts.exponent);
  printf("mantisa = %lu\n", d1.parts.mantisa);
}

// int a;

// int b = 100
/*
a & b

0 11111111111 0000000000000000000000000000000000000000000000000000




double a = 1
double b = 2

a |= b;

// a now contains infinity





*/