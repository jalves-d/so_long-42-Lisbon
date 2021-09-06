#	include "../includes/solong.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (n > 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
	else if (n > 0)
		ft_putchar_fd((n + '0'), fd);
	else
		ft_putchar_fd('0', fd);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = 0;
	return (dest);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] && j < size - 1)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*(str) == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (0);
}
