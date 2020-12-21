void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
		*dest++ = *src++;
}
