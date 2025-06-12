#include <unistd.h>

int main(int argc, char **argv)
{
	int s = 0;
	
		char c;
		       c = argv[1];
	if (argc == 2)
	{
		while(argv[1][s])
		{
			if(c[s]	>= 'a' && c[s] <= 'z')
			{
				c[s] = 'z' - (c[s] - 'a');
				write(1, &c[s], 1);
				s++;
			}
			else if(c[s]   >= 'A' && c[s] <= 'Z')
			{
				c[s] = 'Z' - (c[s] - 'A');
				write(1, &c[s], 1);
				s++;
			}
			else
			{
				write(1, &c[s], 1);
				s++;
			}
		}
		 write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return(0);
}
