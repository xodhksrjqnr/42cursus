void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
		*s++ = c;
}
