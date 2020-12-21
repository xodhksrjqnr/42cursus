char	*ft_strrchr(const char *s, int c)
{
	char	*location;

	location = 0;
	while (*s)
	{
		if (*s == c)
			location = (char *)s;
		s++;
	}
	return (location);
}
