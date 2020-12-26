#include <unistd.h>

void	print(int n, int fd)
{
	char	c;

	if (n / 10)
		print(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		print(n, fd);
	}
}
