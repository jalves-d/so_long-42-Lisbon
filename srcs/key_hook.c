
#include "../includes/solong.h"

int	exitgame(t_drgame *drgame)
{
	free(drgame->map);
	exit(1);
}

void movet (t_drgame *drgame, char *map, int keypressed, int i)
{
	if (keypressed == 115)
	{
		*++map = '0';
		*--map = 'P';
	}
	if (keypressed == 100)
	{
		*--map = '0';
		*++map = 'P';
	}
	if (keypressed == 119)
	{
		*map = 'P';
		while (--i >= 0)
			++map;
		*map = '0';
	}
	if (keypressed == 97)
	{
		*map = 'P';
		map = ft_strchr(drgame->map, 'P');
		*map = '0';
	}
}

void	move(t_drgame *drgame, int keypressed)
{
	char	*map;
	int i;

	i = -1;
	if (keypressed == 115)
		--(*map);
	if (keypressed == 100)
		++(*map);
	if (keypressed == 119)
		while (++i < drgame->lnchars)
			--(*map);
	if (keypressed == 97)
		while (++i < drgame->lnchars)
			++(*map);
	map = ft_strchr(drgame->map, 'P');
	if (*map != '1' && *map != 'E')
	{
		movet(drgame, map, keypressed, i);
		drgame->move += 1;
		ft_putnbr_fd(drgame->move, 1);
		write(1, "\n", 1);
	}
	mlx_destroy_image(drgame->mlx.mlx, drgame->player);
}

void	checkdoor(t_drgame *drgame)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!(ft_strchr(drgame->map, 'E')))
	{
		if (drgame->numexit <= 1)
			if (!(ft_strchr(drgame->map, 'X')))
				exitgame(drgame);
		while (drgame->map[i])
		{
			if (drgame->map[i] == 'X')
				count++;
			i++;
		}
		if (count == drgame->numexit - 1)
			exitgame(drgame);
	}
}

int	key_hook(int key, t_drgame *drgame)
{
	if (!(ft_strchr(drgame->map, 'C')))
	{
		while (ft_strchr(drgame->map, 'E'))
		{
			drgame->numexit++;
			*ft_strchr(drgame->map, 'E') = 'X';
		}
	}
	if (key == 119 || key == 97 || key == 100 || key == 115)
		move(drgame, key);
	if (key == 65307)
		exitgame(drgame);
	drimg(drgame, &drgame->player, "./img/personagem.xpm");
	checkdoor(drgame);
	initmap(drgame);
	return (1);
}
