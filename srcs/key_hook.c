#include "../includes/solong.h"

void	moved(int key, t_drgame	*drgame, int pos)
{
	if (key == D)
	{
		if (drgame->map[pos + 1] == 'E' && !havec(drgame))
		{
			drgame->map[pos + 1] = 'P';
			drgame->map[pos] = '0';
			drgame->move++;
			ft_putnbr(drgame->move, 1);
			exitgame(drgame);
		}
		else if (drgame->map[pos + 1] != '1' && drgame->map[pos + 1] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos + 1];
			drgame->map[pos + 1] = 'P';
			drgame->move++;
			ft_putnbr(drgame->move, 1);
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
			drgame->move++;
			ft_putnbr(drgame->move, 1);
			exitgame(drgame);
		}
		else if (drgame->map[pos - 1] != '1' && drgame->map[pos - 1] != 'E')
		{
			drgame->map[pos] = '0';
			drgame->lastitem = drgame->map[pos - 1];
			drgame->map[pos - 1] = 'P';
			drgame->move++;
			ft_putnbr(drgame->move, 1);
		}
	}
	else
		moved(key, drgame, pos);
}

void	moves(int key, t_drgame *dr, int pos)
{
	if (key == S)
	{
		if (dr->map[pos + dr->lnchars] == 'E' && !havec(dr))
		{
			dr->map[pos + dr->lnchars] = 'P';
			dr->map[pos] = '0';
			dr->move++;
			ft_putnbr(dr->move, 1);
			exitgame(dr);
		}
		else if (dr->map[pos + dr->lnchars] != '1' && dr->map[pos + dr->lnchars] != 'E')
		{
			dr->map[pos] = '0';
			dr->lastitem = dr->map[pos + dr->lnchars];
			dr->map[pos + dr->lnchars] = 'P';
			dr->move++;
			ft_putnbr(dr->move, 1);
		}
	}
	else
		movea(key, dr, pos);
}

void	movew(int key, t_drgame *dr)
{
	int	pos;

	pos = 0;
	while (dr->map[pos] != 'P')
		pos++;
	if (key == W)
	{
		if (dr->map[pos - dr->lnchars] == 'E' && !havec(dr))
		{
			dr->map[pos - dr->lnchars] = 'P';
			dr->map[pos] = '0';
			dr->move++;
			ft_putnbr(dr->move, 1);
			exitgame(dr);
		}
		else if (dr->map[pos - dr->lnchars] != '1' && dr->map[pos - dr->lnchars] != 'E')
		{
			dr->map[pos] = '0';
			dr->lastitem = dr->map[pos - dr->lnchars];
			dr->map[pos - dr->lnchars] = 'P';
			dr->move++;
			ft_putnbr(dr->move, 1);
		}
	}
	else
		moves(key, dr, pos);
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
