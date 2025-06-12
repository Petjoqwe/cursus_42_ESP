#include <unistd.h>

int main(int argc, char **argv)
{
	int s = 0;
	if(argc != 2)
	{
	write(1, "\n", 1);
	return(0);
	}
	if(argc == 2)
	{
	while(argv[1][s] == '\t' || argv[1][s] == ' ')
	{
	s++;
	}
	while(argv[1][s] && argv[1][s] != '\t' && argv[1][s] != ' ')
	{
		write(1, &argv[1][s], 1);
		s++;
	}
	write(1, "\n", 1);
	}
	return(0);
}

