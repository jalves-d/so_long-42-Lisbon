#	include "../includes/solong.h"

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
