#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		while(argv[1][i])
		{
			if(argv[1][i] == '\0')
			return 0;	
			while(argv[1][i] && (argv[1][i] == ' '  || argv[1][i] == '\t'))
				i++;
			while(argv[1][i] && argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
				
			if(argv[1][i] == '_') // hemos encontrado barra baja
			{
			i++; // estamos en la siguiente 
			argv[1][i] = argv[1][i] - 32; // la hacemos mayuscula
			write(1, &argv[1][i], 1);
		       	i++;	// imprimimos
			}
			 // pasamos al siguiente caracter
		}
		write(1, "\n", 1);
		return 0;
	}

	else
		write(1, "\n", 1);
	return 0;
}
