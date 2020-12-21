int		ft_atoi(const char *s)
{
	int		total;
	int		flag;

	while (*s == ' ' || *s == '\t')
		s++;
	flag = 0;
	if (*s == '-')
	{
		flag = 1;
		s++;
	}
	if (!(*s >= '0' && *s <= '9'))
		return (0);
	total = 0;
	while (*s >= '0' && *s <= '9')
		total = total * 10 + *s++ - 48;
	if (flag == 1)
		total *= -1;
	return (total);
}
