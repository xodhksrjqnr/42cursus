#include "libft.h"
#include "stdlib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len <= start)
		len = 0;
	if (!(result = (char *)malloc(len + 1 * sizeof(char))))
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
