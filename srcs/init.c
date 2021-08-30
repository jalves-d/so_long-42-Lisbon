
# include "../includes/solong.h"

void errormessage()
{
	write(1, "Error !\n", 8);
	exit(1);
}

void	drawmapitens(t_drgame *drgame, int x, int y, int z)
{
	if (drgame->map[z + drgame->numb] == 'P')
		drawimgs(drgame, drgame->player, x, y * 39);
	if (drgame->map[z + drgame->numb] == 'C')
		drawimgs(drgame, drgame->sword, x, y * 39);
	if (drgame->map[z + drgame->numb] == 'E' || drgame->map[z + drgame->numb] == 'X')
		drawimgs(drgame, drgame->exit, x, y * 39);
}

void	drawimgs(t_drgame *drgame, void *pximg, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			mlx_put_image_to_window(drgame->mlx.mlx, drgame->mlx.mlx_win , pximg, j, i);
			i++;
		}
		j++;
	}
}

void	initmap(t_drgame *drgame)
{
	int	init;

	while (drgame->y < (drgame->linenum - 1))
	{
		init = -1;
		while (init++ < drgame->lnchars)
		{
			if(drgame->map[init + drgame->numb] != '1')
			{
				drawimgs(drgame, drgame->ground, drgame->x += 40, drgame->y * 39);
				drawmapitens(drgame, drgame->x, drgame->y, init);
			}
			else
				drawimgs(drgame, drgame->tree, drgame->x += 40, drgame->y * 39);
		}
		drgame->y++;
		drgame->numb = drgame->lnchars * drgame->y;
	}
	mlx_put_image_to_window(drgame->mlx.mlx, drgame->mlx.mlx_win, drgame->mlx.mlx_img, 0, 0);
}
