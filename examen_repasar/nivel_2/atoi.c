#include <stdio.h>

int ft_atoi(char *str)
{
	int signo = 1;
	int s = 0;
	int result = 0;

	while(str[s] <= 32)
	{
		s++;
	}

	if(str[s] == '-')
	{
		signo = signo * -1;
		s++;
	}
	else if(str[s] == '+')
	{
		s++;
	}

	while(str[s] >= '0' && str[s] <= '9')
	{
		result = result * 10 + (str[s] - '0');
				s++;
	}
	return(result * signo);
}

	int main()
	{
		int result = ft_atoi(" -42");
		printf("%d\n", result);
		return 0;
	}
