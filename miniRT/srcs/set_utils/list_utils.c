#include "list.h"

int	list_atoi(char **line, int *num)
{
	if (**line == '-')
		return (0);
	while (**line >= '0' && **line <= '9')
	{
		*num = *num * 10 + **line - 48;
		(*line)++;
	}
	return (1);
}

int	cal_color(char **line, long long *color)
{
	int	tmp;
	int	count;

	while (**line == ' ')
		(*line)++;
	count = 0;
	while (count++ < 2)
	{
		tmp = 0;
		if (!list_atoi(line, &tmp))
			return (0);
		if (**line != ',' && !(tmp >= 0 && tmp <= 255))
			return (0);
		(*line)++;
		*color = *color << 8;
		*color += tmp;
	}
	tmp = 0;
	list_atoi(line, &tmp);
	if (**line != ' ' && !(tmp >= 0 && tmp <= 255))
		return (0);
	(*line)++;
	*color = *color << 8;
	*color += tmp;
	return (1);
}

void	list_atoi_f(char **line, float *num)
{
	char	flag;
	float	tmp;
	int	count;

	flag = 0;
	tmp = 0;
	if (**line == '-')
	{
		flag = 1;
		(*line)++;
	}
	while (**line >= '0' && **line <= '9')
	{
		*num = *num * 10 + **line - 48;
		(*line)++;
	}
	if (**line == '.')
	{
		(*line)++;
		count = 10;
		while (**line >= '0' && **line <= '9')
		{
			tmp = tmp + ((float)(**line - 48) / count);
			(*line)++;
			count *= 10;
		}
	}
	*num += tmp;
	if (flag == 1)
		*num *= -1;
}

int	cal_loca(char **line, float *x, float *y, float *z)
{
	while (**line == ' ')
		(*line)++;
	list_atoi_f(line, x);
	if (**line != ',')
		return (0);
	(*line)++;
	list_atoi_f(line, y);
	if (**line != ',')
		return (0);
	(*line)++;
	list_atoi_f(line, z);
	if (**line != ' ')
		return (0);
	(*line)++;
	return (1);
}
