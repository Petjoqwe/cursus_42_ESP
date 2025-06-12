#include <unistd.h>

int main() // paso 0 hecho
{
	int i = 1;
	char c;
	while(i <= 100) // paso 1 hecho
	{
		if(i % 3 == 0 && i % 5 == 0) // paso 3
                {
                        write(1, "fizzbuzz\n", 9);
                }

		else if(i % 3 == 0)
		{
			write(1, "fizz\n", 5);
		}
		
		else if(i % 5 == 0) // paso 2 hecho
		{
			write(1, "buzz\n", 5);
		}
		else
		{
			if(i > 9)
			{
				write(1, &"0123456789"[i / 10], 1);	
			}
				write(1, &"0123456789"[i % 10], 1);
				write(1, "\n", 1);
		}
		i++;
	}
	return(0);
}
