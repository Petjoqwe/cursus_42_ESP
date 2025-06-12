#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		int k = 0;
		while(argv[1][i])
		{
			while(k < i && argv[1][k] != argv[1][i])
				k++;
			if(k == i)
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while(argv[2][i])
		{
			int argv1_found = 0;
			k = 0;
			while(k < i && argv[2][i] != argv[1][k])
				k++;
			if(argv1_found == 0 && k == i)
				write(1, &argv[2][i], 1);
			i++;
		}
		 write(1, "\n", 1);
		return 0;
	}
	else
		write(1, "\n", 1);
	return 0;
}

	
