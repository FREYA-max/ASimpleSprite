# include <stdbool.h>
# include "../so_long.h"


bool check_walls (t_data *data)
{
	int col;
	int row;

	row = 0;
	while (row < data -> rows) {
		if (data -> map[row][0] != '1' && data -> map[row-1][data -> cols -1] != '1')
			return (0);
		row++;

	}

	col = 0;
	while (col < data -> cols) {
		if (data -> map[0][col] != '1' || data -> map[rows-1][col] != '1')
			return (0);
		col++;
	}
	return (true);

}

bool check_chars (t_data *data)
{
	int col;
	int row;
	int playerCount;
	int collectibleCount;
	int wallCount;
	int exitCount;

	playerCount = collectibleCount = exitCount= 0;

	row = 0;
	while (row < data -> rows) {
		col = 0;
		while (col < data -> cols) {
			char allias;
			allias = data -> map[row][col];
			if (allias != '1' && allias != 'P' && allias != 'E' && allias != '0' && allias != 'C')
				return (false);
			if (allias == 'P') {
				data -> p_x = col;
				data -> p_y = row;
				playerCount++;
			}
			else if (allias == 'C')
				collectibleCount++;
			else if (allias == 'E')
				exitCount++;
			col++;
		}
		row++;
	}
	if (playerCount != 1 || exitCount != 1 || collectibleCount < 1)
		return (false);
	return (true);
}


void flood_will ( t_data *data, int col, int row, char **temp_map)
