#ifndef FDF_H
#define FDF_H

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"
#include "draw.h"

# define WIDTH 1280
# define HEIGHT 720

// Structure principal para el programa

typedef struct s_fdf
{
    mlx_t       *mlx;
    mlx_image_t *img;
    int         **z_matrix;
    int         width;
    int         height;
    int         z_min;
    int         z_max;
    float       zoom;
    float       x_offset;
    float       y_offset;
}   t_fdf;

void    free_matrix(int **matrix, int height);
void    error_exit(const char *msg);

#endif
