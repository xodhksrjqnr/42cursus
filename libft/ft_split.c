#include "libft.h"
#include <stdlib.h>

static char		*new_arr(char const *s, char c)
{
	char	*result;
	int		len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len] = 0;
	ft_memcpy(result, s, len);
	return (result);
}

static int		next_location(char const *s, char c)
{
	int		len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	return (len);
}

static int		check_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s)
	{
		len++;
		while (*s != c)
			s++;
		while (*s == c)
			s++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		count;
	int		location;

	if (!s)
		return (0);
	len = check_len(s, c);
	if (!(result = (char **)malloc(len + 1 * sizeof(char *))))
		return (0);
	count = 0;
	location = 0;
	while (count < len)
	{
		*(result + count++) = new_arr(s + location, c);
		location = next_location(s + location, c);
	}
	return (result);
}
