void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
	{
		if (*src == c)
			return ;
		*dest++ = *src++;
	}
}
