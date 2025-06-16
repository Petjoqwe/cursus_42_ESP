#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;	
	}
	return result;
}

int ft_isprime(int n)
{
	int i = 2;

	while(i * i <= n)
	{
		if(n % i == 0)
			return 0;
				i++;
	}
	return 1;
}

void ft_putnbr(int n)
{	
	char c;
	if(n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = n % 10 + ('0');
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
	int num = 0; 
	num = ft_atoi(argv[1]);
	int i = 2;
	int sum = 0;
	while(i <= num)
	{
		if(ft_isprime(i))
			sum = sum + i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return 0;
	}
	else
		write(1, "\n", 1);
	return 0;
}


