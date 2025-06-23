#include <stdlib.h>

static int ft_numlen(long n)
{
	int len = 1;

	if(n < 0)
	{
		n = -n;
		len++;
	}
	if(n >= 10)
	{
		n = n / 10;
		len++;
	}
	return len;
}

char *ft_itoa(int n)
{
	long num = n;
	int len = ft_numlen(num);
	char *str = malloc(sizeof(char) * (len + 1));
	if(!str)
	{
		return NULL;
	}
	str[len] = '\0';
	if(str[0] == '-')
	{
		str[0] = '-';
		num = -num;
	}

	while(--len >= 0 && str[len] != '-')
	{
		str[len] = num + '0' + (str[len] % 10);
		num = num / 10;
	}
	return str;
}

