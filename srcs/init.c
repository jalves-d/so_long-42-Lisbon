#	include "../includes/solong.h"

void	errormessage(void)
{
	write(1, "Error !\n", 8);
	exit(1);
}

void	drawmapitens(t_drgame *drgame, int x, int y, int z)
{
	if (drgame->map[z + drgame->numb] == '0')
		drawimgs(drgame, drgame->ground, x, y);
	if (drgame->map[z + drgame->numb] == 'P')
		drawimgs(drgame, drgame->player, x, y);
	if (drgame->map[z + drgame->numb] == 'C')
		drawimgs(drgame, drgame->sword, x, y);
	if (drgame->map[z + drgame->numb] == 'E')
		drawimgs(drgame, drgame->exit, x, y);
}

void	drawimgs(t_drgame *drgame, char *imgname, int x, int y)
{
	int	width;
	int	height;

	drgame->addr = mlx_get_data_addr(drgame->mlx.mlx_img, &drgame->bpp, &drgame->linenum, &drgame->numexit);
	drgame->mlx.mlx_img = mlx_xpm_file_to_image(drgame->mlx.mlx, imgname, &width, &height);
	if (!(drgame->mlx.mlx_img))
		write(2, "IMG Error !", 12);
	mlx_put_image_to_window(drgame->mlx.mlx, drgame->mlx.mlx_win, drgame->mlx.mlx_img, x, y);
}

void	initmap(t_drgame *drgame)
{
	int	init;

	while (drgame->y < ((drgame->linenum - 1) * 40))
	{
		init = 0;
		while (init < drgame->lnchars)
		{
			if (drgame->map[init + drgame->numb] != '1')
			{
				drgame->x += 40;
				drawmapitens(drgame, drgame->x, drgame->y, init);
			}
			else
				drawimgs(drgame, drgame->tree, drgame->x += 40, drgame->y);
			init++;
		}
		drgame->x = -40;
		drgame->y += 40;
		drgame->numb += drgame->lnchars;
	}
}
