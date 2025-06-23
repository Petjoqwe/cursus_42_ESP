// main.c
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

int main(void)
{
	if (mlx_init(WIDTH, HEIGHT, "FdF - MLX42", true) == NULL)
	{
		fprintf(stderr, "mlx_init failed\n");
		return EXIT_FAILURE;
	}

	mlx_loop(mlx_get_instance());
	mlx_terminate(mlx_get_instance());
	return EXIT_SUCCESS;
}
