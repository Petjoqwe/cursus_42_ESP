#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		printf("\n");
		return(0);
	}

	int a =  atoi(argv[1]);
	int op = argv[2][0];
	int b =  atoi(argv[3]);
	int result = 0;
	if(op == '+')
	{
		result = a + b;
	}
	else if(op == '-')
	{
		result = a - b;
	}
	else if(op == '*')
	{
		result = a * b;
	}
	else if (op == '/')
	{
		result = a / b;
	}
	else if (op == '%')
	{
		result = a % b;
	}
	
	printf("%d\n", result);
	return 0;
}

