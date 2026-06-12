#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
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

int     count_row(char *path, t_data *data);
char    **allocate_map(t_data *data);
int     fill_map(char *path, t_data *data);
bool    check_walls(t_data *data);
bool    check_chars(t_data *data);
bool    check_map(t_data *data);
char    **copy_map(t_data *data);
void    flood_fill(t_data *data, int x, int y, char **temp_map);
bool    check_path(t_data *data);
void    free_map(char **map, int rows);

#endif
