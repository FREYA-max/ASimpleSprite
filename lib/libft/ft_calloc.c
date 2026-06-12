                                                          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠸⣿⣇⢿⡇⢰⣬⠙⠛⠿⠿⣿⣿⣿⣿⣿⠿⠛⠁⠀⣠⣾⠟⣯⣾⣼⢹⡟⠁⡎⠀⢰⡶⠿⠟⠋⡛⠛⠓⠾⢭⣝⣛⠻⠿⢿⣿⣿⣿⣿⣿  */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	if (num != 0 && (num * size) / num != size)
		return (NULL);
	result = malloc(num * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, num * size);
	return (result);
}

