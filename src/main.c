#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	
	if (!count_row(argv[1], &data))
		return (ft_printf("Error\nInvalid map geometry\n"), 1);
	
	
	data.map = allocate_map(&data);
	if (!data.map)
		return (1);
	
	
	if (!fill_map(argv[1], &data))
	{
		free_map(data.map, data.rows);
		return (1);
	}
	
	
	if (!check_map(&data))
	{
		ft_printf("Error\nMap invalid (walls, chars or path error)\n");
		free_map(data.map, data.rows); // On évite les fuites de mémoire !
		return (1);
	}

	ft_printf("Map is valid\n");
	
	
	
	
	free_map(data.map, data.rows);
	return (0);
}
