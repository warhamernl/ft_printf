#include "libft.h"
#include <stdio.h>

static int	ft_numlen(unsigned long long nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static char	ft_base(unsigned long long n, int base, int times)
{
	int temp;
	int con;
	int		i;

	i = 0;
	while (i < times)
	{
		temp = n % base;
		i++;
	}
	if (temp > 9)
		con = temp - 10 + 'A';
	else
		con = temp + '0';
	return (con);
}

char		*ft_itoa_base_len(unsigned long long n, int base, int nega)
{
	int a;
	char *string;
	int b;

	a = ft_numlen(n, base);
	b = a;
	string = ft_strnew(a + nega);
	if (base <= 1 || base >= 37 || !string)
		return (NULL);
	if (nega == 1)
		string[0] = '-';
	while (nega != b)
	{
		string[nega] = ft_base(n, base, a);
		n /= base;
		nega++;
		a--;
	}
	return (string);
}


int		main(void)
{
	unsigned long long n;

	n = 10;

	printf("%s",ft_itoa_base_len(n, 10, 1));

}