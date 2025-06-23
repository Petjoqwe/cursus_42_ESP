#include "fdf.h"

void free_matrix(int **matrix, int height)
{
    int i = 0;
    while (i < height)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
