#include <unistd.h>

int main(int argc, char **argv)
{
	char index[255] = {0};
	int i = 0;
	if(argc == 3)
	{
		while(argv[1][i])
		{
			char c = argv[1][i];
			if(index[c] == 0)
			{
				index[c] = 1;
				write(1, &c, 1);
			}
			i++;
		}
		i = 0;
		while(argv[2][i])
		{
			char c = argv[2][i];
			if(index[c] == 0)
			{
				index[c] = 1;
				write(1, &c, 1);
			}
			i++;
		}
		write(1, "\n", 1);
		return 0;
	}
	else
		write(1, "\n", 1);
	return 0;
}

	
