#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <instd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_data {
	char **map;
	int rows;
	int cols;
	int p_x;
	int p_y;
	int collectibles;
	bool exit_found;
}t_data;

#endif
