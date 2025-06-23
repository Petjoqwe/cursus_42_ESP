#include <stdio.h>
#include <stdlib.h>


static int num_len(long n)
{
	int len = 1;
	if(n < 0)
	{
		n = -n;
		len++;
	}

	while(n >= 10)
	{
		n = n / 10;
		len++;
	}
	return len;
}

char *itoa(int num)
{
		long n = num;
		int len = num_len(n);

		char *str = malloc(sizeof(char) * (len + 1));
		if(!str)
		{
			return NULL;
		}
		str[len] = '\0';

		if(n < 0)
		{
			n = -n;
			str[0] = '-';
		}

		else if(n == 0)
		{
			str[0] = '0';
			return str;
		}

		while(len-- > 0 && str[len] != '-')
		{
			str[len] = (n % 10) + '0';
			n = n / 10;
		}

		return str;
}

int main()
{
	char *str = itoa(1234);
	printf("%s", str);
	return 0;
}
