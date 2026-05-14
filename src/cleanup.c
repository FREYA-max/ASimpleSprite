#include "/home/godfist/langageC/mazeSpace/so_long.h"

void free_map (char **map) 
{
	int i;
	if (!map)
		return;
	i = 0;
	while (map[i]) { //free one by one the maps's rows
		free(map[i]);
		i++;
	}
	free(map);
	
}
