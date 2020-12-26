#include "libft.h"
#include <stdlib.h>

char	*new_arr(char *start, char *end)
{
	char	*result;
	char	*tmp;
	int		len;

	len = end - start + 1;
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	tmp = result;
	while (start != end + 1)
		*tmp++ = *start++;
	*tmp = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	*convert_s;
	char	**result;
	int		count;

	convert_s = ft_strtrim(s, &c);
	tmp = convert_s;
	count = 0;
	while (*tmp)
		if (*tmp++ == c)
			count++;
	if (!(result = (char **)malloc(count + 2 * sizeof(char *))))
		return (0);
	result[count + 1] = 0;
}
