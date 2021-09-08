#	include "../includes/solong.h"

static size_t	ft_len(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_signal(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = ft_len(n);
	str = (char *)malloc(i + 1);
	if (!(str))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		k = 1;
	}
	else
		k = 0;
	while (i > k)
	{
		i--;
		str[i] = '0' + n % 10 * ft_signal(n);
		n = n / 10;
	}
	return (str);
}

void	ft_putnbr(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
}

int	checkendl(t_drgame *drgame)
{
	int i;

	i = 0;
	while (i < drgame->lnchars)
	{
		if (drgame->map[ft_strlen(drgame->map) - drgame->lnchars + i - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
