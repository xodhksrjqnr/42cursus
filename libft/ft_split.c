#include "libft.h"
#include <stdlib.h>

static char		*new_arr(char *start, char *end)
{
	char	*result;
	char	*tmp;
	int		len;

	len = end - start;
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	tmp = result;
	while (start != end)
		*tmp++ = *start++;
	*tmp = 0;
	return (result);
}

static void		make_result(char **result, char *s, int c)
{
	char	*start;
	int		count;

	count = 0;
	start = s;
	while (*(result + count))
	{
		if (*s == c || *s == 0)
		{
			*(result + count++) = new_arr(start, s);
			start = s + 1;
		}
		s++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	*convert_s;
	char	**result;
	char	*tmp;
	int		len;
	
	if (!s)
		return (0);
	convert_s = ft_strtrim(s, &c);
	tmp = convert_s;
	len = 0;
	while (*tmp)
		if (*tmp++ != c)
			len++;
	if (!(result = (char **)malloc(len + 1 * sizeof(char *))))
		return (0);
	result[len] = 0;
	make_result(result, convert_s, c);
	free(convert_s);
	return (result);
}
