#include "get_next_line.h"

static char	*add_char(char *str, char chr)
{
	int		count;
	char	*result;

	count = 0;
	while (*(str + count))
		count++;
	result = malloc(count + 2);
	if (!result)
	{
		free(str);
		return (0);
	}
	result[count + 1] = 0;
	result[count] = chr;
	count = 0;
	while (*(str + count))
	{
		*(result + count) = *(str + count);
		count++;
	}
	free(str);
	return (result);
}

int	get_next_line(char **line)
{
	char	buff;
	char	*data;
	int		result;

	if (!line || !(data = malloc(2)))
		return (-1);
	data[1] = 0;
	data[0] = 0;
	while ((result = read(0, &buff, 1)) > 0)
	{
		if (buff == '\n')
			break ;
		data = add_char(data, buff);
		if (!data)
			return (-1);
	}
	if (result == -1)
		return (-1);
	*line = data;
	if (result == 1)
		return (1);
	else
		return (0);
}
