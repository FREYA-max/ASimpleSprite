
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last;
	unsigned char	uc;

	if (!s)
		return (NULL);
	last = NULL;
	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == (char)uc)
			last = (char *)&s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (last);
}

