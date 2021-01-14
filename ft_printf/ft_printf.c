#include "ft_printf.h"
#include "./Libft/libft.h"

t_list	*make_list(char *start, char *end)
{
	t_list	*result;

	result = newformat();
	
}

int		ft_printf(const char *format, ...)
{
	char	*head;
	char	*tail;
	char	*div;
	int		count;

	if (!(div = ft_strchr(format, '%')))
	{
		head = format;
		while (*format)
			write(1, format++, 1);
		return (format - head);
	}
	if (!(head = (char *)malloc(div - format + 1)))
		return (-1);
	count = 0;
	while (format != div)
		*(head + count++) = *format++;
	*(head + count) = 0;
	while ((div = ft_strchr(++format, '%')))
		format = make_list(format, div);
}
