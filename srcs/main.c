#include "../includes/solong.h"

int	windowsize(t_drgame *drgame)
{
	initmap(drgame);
	return (1);
}

int	exitgame(t_drgame *drgame)
{
	free(drgame->map);
	exit(1);
}

void	drgamedatas(t_drgame *dr)
{
	dr->mlx.mlx = mlx_init();
	dr->mlx.mlx_win = mlx_new_window(dr->mlx.mlx, dr->width, dr->height, "Game name");
	dr->player = "./img/personagem.xpm";
	dr->exit = "./img/personagem.xpm";
	dr->sword = "./img/bau.xpm";
	dr->tree = "./img/piso.xpm";
	dr->ground = "./img/parede.xpm";
	dr->mlx.mlx_img = mlx_new_image(dr->mlx.mlx, dr->width, dr->height);
	dr->numb = 0;
	dr->y = 0;
	dr->x = -40;
	dr->addr = NULL;
	initmap(dr);
}

void	solong(int argc, char **argv, t_drgame *drgame)
{
	int	sizename;

	sizename = ft_strlen(argv[1]);
	if (argc < 3)
	{
		if (argv[1][sizename - 1] == 'r' && argv[1][sizename - 2] == 'e')
		{
			if (argv[1][sizename - 3] == 'b' && argv[1][sizename - 4] == '.')
				validmap(argv[1], drgame);
		}
		else
		{
			write(1, "Error \n", 8);
			exit(1);
		}
	}
	else
	{
		write(1, "Error \n", 8);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_drgame	drgame;

	solong(argc, argv, &drgame);
	mlx_key_hook(drgame.mlx.mlx_win, key_hook, &drgame);
	mlx_hook(drgame.mlx.mlx_win, 15, 1L << 16, windowsize, &drgame);
	mlx_hook(drgame.mlx.mlx_win, 33, 1L << 5, exitgame, &drgame);
	mlx_loop(drgame.mlx.mlx);
}
