
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	i_2;

	i = 0;
	i_2 = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[i_2])
		{
			while (haystack[i + i_2] == needle[i_2] && i + i_2 < n)
			{
				if (needle[i_2 + 1] == '\0')
					return ((char *)haystack + i);
				i_2++;
			}
			i_2 = 0;
		}
		i++;
	}
	return (NULL);
}

