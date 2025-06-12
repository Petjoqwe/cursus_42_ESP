#include <unistd.h>

int main(int argc, char **argv)
{
	int s = 0;
	char c;

	if(argc == 2)
	{
		while(argv[1][s])
		{
			c = argv[1][s];

			if(c >= 'A' && c <= 'Z')
			{
				write(1, "_", 1);

				c = c + 32;
				write(1, &c, 1);
				s++;
			}
			else
			{
				write(1, &c, 1);
				s++;
			}
			
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return 0;

}
