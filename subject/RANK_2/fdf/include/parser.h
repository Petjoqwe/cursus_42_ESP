#ifndef PARSER_H
#define PARSER_H

#include "fdf.h"

int     **parse_map(const char *filename, int *width, int *height, int *z_min, int *z_max);

#endif
