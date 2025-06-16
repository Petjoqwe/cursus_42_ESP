#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		int first_word = 1;
		while(argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                                i++;
		while(argv[1][i])
		{
			if(first_word == 0)
				write(1, "   ", 3);
			else
				first_word = 0;
			while(argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			{	
				write(1, &argv[1][i], 1);
				i++;
			}
			while(argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;
		}
		write(1, "\n", 1);
		return 0;
	}
	else
		write(1, "\n", 1);
	return 0;
}
