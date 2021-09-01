
# include "../includes/solong.h"

int	windowsize(t_drgame *drgame)
{
	initmap(drgame);
	return (1);
}

void	drimg(t_drgame *drgame, void **pximg, char *imgname)
{
	int				width;
	int				height;

	*pximg = mlx_xpm_file_to_image(drgame->mlx.mlx, imgname, &width, &height);
	if (!(*pximg))
		write(2, "IMG Error !", 12);
}

void	drgamedatas(t_drgame *drgame)
{
	drgame->mlx.mlx = mlx_init();
	drgame->mlx.mlx_win = mlx_new_window(drgame->mlx.mlx,drgame->width, drgame->height, "Game name");
	drgame->mlx.mlx_img = mlx_new_image(drgame->mlx.mlx, drgame->width, drgame->height);
	drimg(drgame, &drgame->player, "./img/personagem.xpm");
	drimg(drgame, &drgame->exit, "./img/personagem.xpm");
	drimg(drgame, &drgame->sword, "./img/bau.xpm");
	drimg(drgame, &drgame->tree, "./img/piso.xpm");
	drimg(drgame, &drgame->ground, "./img/parede.xpm");
	drgame->numb = 0;
	drgame->y = 0;
	drgame->x = -40;
	initmap(drgame);
}

void	solong(int argc, char **argv, t_drgame *drgame)
{
	int sizename;

	sizename = ft_strlen(argv[1]);
	if (argc < 3)
	{
		if (argv[1][sizename - 1] == 'r' && argv[1][sizename - 2] == 'e' && argv[1][sizename - 3] == 'b' &&
				argv[1][sizename - 4] == '.')
	   		validmap(argv[1], drgame);
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
	t_drgame drgame;

	solong(argc, argv, &drgame);
	mlx_key_hook(drgame.mlx.mlx_win, key_hook, &drgame);
	mlx_hook(drgame.mlx.mlx_win, 15, 1L << 16, windowsize, &drgame);
	mlx_hook(drgame.mlx.mlx_win, 33, 1L << 5, exitgame, &drgame);
	mlx_loop(drgame.mlx.mlx);
}
