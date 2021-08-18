#include "get_next_line.h"

int	main(void)
{
	int		result;
	char	*line;

	line = 0;
	while ((result = get_next_line(&line)) > 0)
		printf("%s, %d\n", line, result);
	return (0);
}
