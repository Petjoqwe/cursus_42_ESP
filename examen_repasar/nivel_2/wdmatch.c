#include <unistd.h>

int main (int argc, char **argv)
{
	if(argc == 3)
	{
			int j = 0;
			int i = 0;	
		while(argv[1][i])
		{
			while(argv[2][j] && argv[2][j] != argv[1][i])
			{
				j++;
			}	

			if(argv[2][j] == '\0')
			{
				write(1, "\n", 1);
				return 0;
			}
			j++;
			i++;
		}
		write(1, argv[1], i);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return 0;
}
