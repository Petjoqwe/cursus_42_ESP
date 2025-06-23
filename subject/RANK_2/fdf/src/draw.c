#include "draw.h"

static void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    while (1)
    {
        mlx_put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

static int get_color(int z, int z_min, int z_max)
{
    if (z_max == z_min) return 0xFFFFFFFF;
    float ratio = (float)(z - z_min) / (z_max - z_min);
    int r = 0xFF * ratio;
    int g = 0xFF * (1 - ratio);
    return (0xFF << 24) | (r << 16) | (g << 8) | 0xFF;
}

void draw_map(t_fdf *fdf)
{
    int x, y;
    for (y = 0; y < fdf->height; y++)
    {
        for (x = 0; x < fdf->width; x++)
        {
            int x0 = fdf->x_offset + (x - y) * fdf->zoom;
            int y0 = fdf->y_offset + (x + y) * fdf->zoom / 2 - fdf->z_matrix[y][x];
            if (x < fdf->width - 1)
            {
                int x1 = fdf->x_offset + ((x + 1) - y) * fdf->zoom;
                int y1 = fdf->y_offset + ((x + 1) + y) * fdf->zoom / 2 - fdf->z_matrix[y][x + 1];
                draw_line(fdf->img, x0, y0, x1, y1, get_color(fdf->z_matrix[y][x], fdf->z_min, fdf->z_max));
            }
            if (y < fdf->height - 1)
            {
                int x1 = fdf->x_offset + (x - (y + 1)) * fdf->zoom;
                int y1 = fdf->y_offset + (x + (y + 1)) * fdf->zoom / 2 - fdf->z_matrix[y + 1][x];
                draw_line(fdf->img, x0, y0, x1, y1, get_color(fdf->z_matrix[y][x], fdf->z_min, fdf->z_max));
            }
        }
    }
}
