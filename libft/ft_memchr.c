void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
}
