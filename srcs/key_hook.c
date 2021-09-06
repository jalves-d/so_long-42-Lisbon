#include "../includes/solong.h"

int	havec(t_drgame *drgame)
{
	int	i;

	i = 0;
	while (drgame->map[i])
	{
		if (drgame->map[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

void	moved(int key, t_drgame	*drgame, int pos)
{
	if (key == D)
	{
		if (drgame->map[pos + 1] == 'E' && !havec(drgame))
		{	
			drgame->map[pos + 1] = 'P';
			drgame->map[pos] = '0';
			exitgame(drgame);
		}
		else if (drgame->map[pos + 1] != '1' && drgame->map[pos + 1] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos + 1];
			drgame->map[pos + 1] = 'P';
		}
	}
}

void	movea(int key, t_drgame	*drgame, int pos)
{
	if (key == A)
	{
		if (drgame->map[pos - 1] == 'E' && !havec(drgame))
		{
			drgame->map[pos - 1] = 'P';
			drgame->map[pos] = '0';
			exitgame(drgame);
		}
		else if (drgame->map[pos - 1] != '1' && drgame->map[pos - 1] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos - 1];
			drgame->map[pos - 1] = 'P';
		}
	}
	else
		moved(key, drgame, pos);
}

void	moves(int key, t_drgame *drgame, int pos)
{
	if (key == S)
	{
		if (drgame->map[pos + drgame->lnchars] == 'E' && !havec(drgame))
		{
			drgame->map[pos + drgame->lnchars] = 'P';
			drgame->map[pos] = '0';
			exitgame(drgame);
		}
		else if (drgame->map[pos + drgame->lnchars] != '1' && drgame->map[pos + drgame->lnchars] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos + drgame->lnchars];
			drgame->map[pos + drgame->lnchars] = 'P';
		}
	}
	else
		movea(key, drgame, pos);
}

void	movew(int key, t_drgame *drgame)
{
	int	pos;

	pos = 0;
	while (drgame->map[pos] != 'P')
		pos++;
	if (key == W)
	{
		if (drgame->map[pos - drgame->lnchars] == 'E' && !havec(drgame))
		{
			drgame->map[pos - drgame->lnchars] = 'P';
			drgame->map[pos] = '0';
			exitgame(drgame);
		}
		else if (drgame->map[pos - drgame->lnchars] != '1' && drgame->map[pos - drgame->lnchars] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos - drgame->lnchars];
			drgame->map[pos - drgame->lnchars] = 'P';
		}
	}
	else
		moves(key, drgame, pos);
}

int	key_hook(int key, t_drgame *drgame)
{
	if (key == ESC)
		exitgame(drgame);
	if (key == W || key == S || key == A || key == D)
		movew(key, drgame);
	mlx_destroy_image(drgame->mlx.mlx, drgame->mlx.mlx_img);
	drgame->mlx.mlx_img = mlx_new_image(drgame->mlx.mlx, drgame->width, drgame->height);
	drgame->y = 0;
	drgame->x = -40;
	drgame->numb = 0;
	drgame->addr = NULL;
	initmap(drgame);
	return (1);
}
