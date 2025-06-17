#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	long num = atoi(argv[1]);
	int i = 2;
	if(argc == 2)
	{
	if(num == 1)
		printf("1");
	while(num >= i)
	{
			if(num % i == 0)
		{
			printf("%d", i);
			num = num / i;
			if(num > 1)
				printf("*");
		}
		else
			i++;
	}
	printf("\n");
	}
	else
		printf("\n");
	return 0;
}
