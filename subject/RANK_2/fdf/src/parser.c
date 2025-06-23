#include "parser.h"

static int  count_words(const char *line)
{
    int count = 0;
    int in_word = 0;
    while (*line)
    {
        if (*line != ' ' && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*line == ' ')
            in_word = 0;
        line++;
    }
    return count;
}

static int  *parse_line(const char *line, int width, int *z_min, int *z_max)
{
    int *row = malloc(sizeof(int) * width);
    int i = 0;
    char *token;
    char *str = strdup(line);
    char *tofree = str;
    while ((token = strsep(&str, " ")) && i < width)
    {
        if (*token)
        {
            row[i] = atoi(token);
            if (row[i] < *z_min) *z_min = row[i];
            if (row[i] > *z_max) *z_max = row[i];
            i++;
        }
    }
    free(tofree);
    return row;
}

int **parse_map(const char *filename, int *width, int *height, int *z_min, int *z_max)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        error_exit("Cannot open map file");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int **matrix = NULL;
    int rows = 0;
    *z_min = 2147483647;
    *z_max = -2147483648;
    while ((read = getline(&line, &len, file)) != -1)
    {
        if (rows == 0)
            *width = count_words(line);
        rows++;
    }
    rewind(file);
    matrix = malloc(sizeof(int *) * rows);
    int i = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        matrix[i] = parse_line(line, *width, z_min, z_max);
        i++;
    }
    *height = rows;
    free(line);
    fclose(file);
    return matrix;
}
