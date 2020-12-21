void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
		*s++ = 0;
}
