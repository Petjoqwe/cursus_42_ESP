#include <unistd.h>
//#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return(0);
	}	

	else if(argc == 3)

	{
		int i = 0;
		int j = 0;
		int k = 0;
		int print = 0;
		while(argv[1][i])
		{
			print = 0;
			k = 0;
			j = 0;
		while(k < i) // un identificador de letras repetidas.
		{
			if(argv[1][k] == argv[1][i]) // comparador de caracteres repetidos.
			{
				print = 1; // flag para saber si hemos imprimido
				break;
			}
			k++; // pasamos para ver si hay coincidencia ya escrita
		}

		if(print == 0) // si no hemos encontrado letra repe
		{
			while(argv[2][j]) // se encarga de imprimir coincidencias
			{
				if(argv[1][i] == argv[2][j]) // si hay coincidencia
						{
							write(1, &argv[1][i], 1);
							break;
						}
				j++; 
			}
		}
		i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return 0;
}
