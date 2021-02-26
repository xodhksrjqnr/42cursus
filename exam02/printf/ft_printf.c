#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	check_leng_x(unsigned int num, int count)
{
	if (num / 16)
		count = check_leng_x(num / 16, ++count);
	return (count);
}

static void	print_num_x(unsigned int num)
{
	char	tmp;

	if (num / 16)
		print_num_x(num / 16);
	num %= 16;
	tmp = "0123456789abcdef"[num];
	write(1, &tmp, 1);
}

static int x_printf(int first, int second, unsigned int num)
{
	int		len;
	int		zero;

	len = check_leng_x(num, 1);
	zero = 0;
	if (len < second)
		zero = second - len;
	if (first > len + zero)
	{
		while (first-- != len + zero)
			write(1, " ", 1);
	}
	while (zero-- > 0)
		write(1, "0", 1);
	print_num_x(num);
}

static void	print_num(int num)
{
	char	tmp;

	if (num / 10)
		print_num(num / 10);
	num %= 10;
	if (num < 0)
		num *= -1;
	tmp = num + 48;
	write(1, &tmp, 1);
}

static int	check_leng_d(int num, int count)
{
	if (num / 10)
		count = check_leng_d(num / 10, ++count);
	return (count);
}

static void d_printf(int first, int second, int num)
{
	int		len;
	int		zero;

	len = check_leng_d(num, 1);
	zero = 0;
	if (len < second)
		zero = second - len;
	if (first > len + zero)
	{
		if (num < 0)
			first--;
		while (first-- != len + zero)
			write(1, " ", 1);
	}
	if (num < 0)
		write(1, "-", 1);
	while (zero-- > 0)
		write(1, "0", 1);
	print_num(num);
}

static int s_printf(int first, int second, char *str)
{
	char	*tmp;
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	if (len > second && second != -1)
		len = second;
	if (first > len)
	{
		while (first-- != len)
			write(1, " ", 1);
	}
	while (len-- > 0)
		write(1, str++, 1);
}

static void	check_num(char **s, int *second)
{
	*second = 0;
	if (**s == '-')
	{
		*second = -1;
		(*s)++;
		while (**s >= 48 && **s <= 57)
			(*s)++;
	}
	else
	{
		while (**s >= 48 && **s <= 57)
		{
			*second = *second * 10 + **s - 48;
			(*s)++;
		}
	}
}

static int	parse(char *s, va_list ap)
{
	int		first;
	int 	second;
	char	*start;

	start = s;
	first = 0;
	while (*s >= 48 && *s <= 57)
		first = first * 10 + *s++ - 48;
	second = -1;
	if (*s == '.')
	{
		s++;
		check_num(&s, &second);
	}
	if (!(*s == 's' || *s == 'd' || *s == 'x'))
		return (0);
	if (*s == 's')
		s_printf(first, second, va_arg(ap, char *));
	else if (*s == 'd')
		d_printf(first, second, va_arg(ap, int));
	else if (*s == 'x')
		x_printf(first, second, va_arg(ap, int));
	return (s - start + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	while (*s)
	{
		count = 0;
		if (*s == '%')
		{
			++s;
			count = parse((char *)s, ap);
			if (!count)
			{
				va_end(ap);
				return (-1);
			}
			s += count;
		}
		else
			write(1, s++, 1);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int	num;

	ft_printf("10.0s |%10.0s|\n", "Hello");
	ft_printf("10.s  |%10.s|\n", "Hello");
	ft_printf("10s   |%10s|\n", "Hello");
	ft_printf("10.4s |%10.4s|\n", "HEllo");
	ft_printf("10.7s |%10.7s|\n", "HEllo");
	ft_printf(".7s   |%.7s|\n", "HEllo");
	ft_printf(".3s   |%.3s|\n", "HEllo");

	ft_printf("d    |%d|\n", 1234);
	ft_printf("3d   |%3d|\n", 1234);
	ft_printf("7d   |%7d|\n", 1234);
	ft_printf(".d   |%.d|\n", 1234);
	ft_printf(".3d  |%.3d|\n", 1234);
	ft_printf(".6d  |%.6d|\n", 1234);
	ft_printf(".6d  |%.6d|\n", -1234);
	ft_printf("3.3d |%3.3d|\n", 1234);
	ft_printf("3.3d |%3.3d|\n", -1234);
	ft_printf("6.3d |%6.3d|\n", 1234);
	ft_printf("6.3d |%6.3d|\n", -1234);
	ft_printf("3.7d |%3.7d|\n", 1234);
	ft_printf("3.7d |%3.7d|\n", -1234);
	ft_printf("9.7d |%9.7d|\n", 1234);
	ft_printf("9.7d |%9.7d|\n", -1234);

	ft_printf("x    |%x|\n", 1234);
	ft_printf("3x   |%3x|\n", 1234);
	ft_printf("7x   |%7x|\n", 1234);
	ft_printf(".x   |%.x|\n", 1234);
	ft_printf(".3x  |%.3x|\n", 1234);
	ft_printf(".6x  |%.6x|\n", 1234);
	ft_printf(".6x  |%.6x|\n", -1234);
	ft_printf("3.3x |%3.3x|\n", 1234);
	ft_printf("3.3x |%3.3x|\n", -1234);
	ft_printf("6.3x |%6.3x|\n", 1234);
	ft_printf("6.3x |%6.3x|\n", -1234);
	ft_printf("3.7x |%3.7x|\n", 1234);
	ft_printf("3.7x |%3.7x|\n", -1234);
	ft_printf("9.7x |%9.7x|\n", 1234);
	ft_printf("9.7x |%9.7x|\n", -1234);

	return (0);
}
