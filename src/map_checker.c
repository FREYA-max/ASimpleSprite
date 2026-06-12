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


char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < data->rows)
	{
		copy[i] = ft_strdup(data->map[i]); 
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(t_data *data, int x, int y, char **temp_map)
{
	if (x < 0 || y < 0 || x >= data->cols || y >= data->rows 
		|| temp_map[y][x] == '1' || temp_map[y][x] == 'V')
		return ;

	temp_map[y][x] = 'V';

	flood_fill(data, x + 1, y, temp_map);
	flood_fill(data, x - 1, y, temp_map);
	flood_fill(data, x, y + 1, temp_map);
	flood_fill(data, x, y - 1, temp_map);
}

bool	check_path(t_data *data)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = copy_map(data);
	if (!temp_map)
		return (false);
	flood_fill(data, data->p_x, data->p_y, temp_map);
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (temp_map[i][j] == 'C' || temp_map[i][j] == 'E')
			{
				free_map(temp_map, data->rows);
				return (false);
			}
			j++;
		}
		i++;
	}
	free_map(temp_map, data->rows);
	return (true);
}

// LA FONCTION MAÎTRESSE QUI ORCHESTRE TOUT
bool	check_map(t_data *data)
{
	if (!check_walls(data))
		return (false);
	if (!check_chars(data)) 
		return (false);
	if (!check_path(data))  
		return (false);
	return (true);
}
