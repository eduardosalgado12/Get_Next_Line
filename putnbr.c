int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(long n)
{
	char	s[12];
	int		i;

	i = 0;
	if (n < 0 && ft_putchar('-'))
		n = -n;
	if (n == 0)
		i += ft_putchar('0');
	while (n > 0 && s[i++] = (n % 10) + '0' )
		n /= 10;
	while (i--)
		ft_putchar(s[i]);
	return (i);
}

