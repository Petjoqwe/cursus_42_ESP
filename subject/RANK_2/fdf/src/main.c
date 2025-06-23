#include "fdf.h"

int main(int argc, char **argv)
{
    t_fdf fdf;

    if (argc != 2)
        error_exit("Usage: ./fdf <map_file>");
    fdf.z_matrix = parse_map(argv[1], &fdf.width, &fdf.height, &fdf.z_min, &fdf.z_max);
    fdf.zoom = 20.0f;
    fdf.x_offset = WIDTH / 2;
    fdf.y_offset = HEIGHT / 2;
    fdf.mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
    if (!fdf.mlx)
        error_exit("MLX42 init failed");
    fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
    if (!fdf.img)
        error_exit("Image creation failed");
    draw_map(&fdf);
    mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
    mlx_loop(fdf.mlx);
    free_matrix(fdf.z_matrix, fdf.height);
    mlx_terminate(fdf.mlx);
    return (0);
}
