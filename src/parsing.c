# include "../so_long.h"

int count_row (char *path, t_data *data)
{
	int fd;
	int current;
	char c;
	int bytes_read;

	current = 0;
	data -> cols = -1;
	data -> rows = 0;

	fd = open (path, O_RDONLY); //read only
	if (fd < 0)
		return (0);
	while((bytes_read = read(fd, &c, 1)) > 0) {
		
		if (c == '\n') {
			if (data -> cols == -1)
				data -> cols = current;
			else if (current != data -> cols)
					return (0);
			data -> rows++;
			current = 0;
		}else 
			current++;


	}
	if (current > 0) {
		if (data -> cols != -1 && current != data -> cols)
			return (0);
		data -> rows++;
		if (data -> cols == -1)
			data -> cold = current;
	}
	close(fd);
}

char **allocate_map (t_data *data)
{
	int i;
	char **map;

	map = malloc(sizeof(char *) * (data -> rows +1));
	if (!map)
		return (NULL);

	i = 0;
	while (i < data -> rows)
	{
		map[i] = malloc(sizeof(char *) * data -> cols + 1));
		if (!map[i]) {
			free(map);
			return (NULL);
		}
		i++;

	}
	map[i] = NULL;
	return (map);

}


int fill_map (char * path, t_data * data) 
{
	int df;
	int col;
	int row;
	char c;

	fd = open (path, O_RDONLY);
	row = 0;
	while (row < data -> rows) {
		col = 0;
		while (col < data -> col) {
			read (fd, &c, 1);
			if ('c' != '\n' || 'c' != '\r') {
				map[row][col] = c;
				x++;
			} 

		}
		data [row][col] = '\0';
		read (fd, &c, 1);
		y++;

	}
	close(fd);
	return (1);

}
