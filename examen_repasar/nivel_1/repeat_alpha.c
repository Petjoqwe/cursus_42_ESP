#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int count = 0;
	if(argc == 2)
		{
			while(argv[1][i])
			{
				count = 0;
				if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
				{
					count = argv[1][i] - 'a';
					if(count > 0)
					{
					while(count >= 0)
					{
						write(1, &argv[1][i], 1);
						count--;
					}
					}
					else
						write(1, &argv[1][i], 1);
					
				}
				else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				{
					count = argv[1][i] - 'A';
                                        if(count > 0)
                                        {
                                        while(count > 0)
                                        {
                                                write(1, &argv[1][i], 1);
                                                count--;
                                        }
                                        }
                                        else
                                                write(1, &argv[1][i], 1);
				}
				i++;
			}
			write(1, "\n", 1);
			return 0;
		}
		else
		{
			write(1, "\n", 1);
			return 0;
		}
		return 0;

}
