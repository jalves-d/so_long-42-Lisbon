/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:03:56 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:03:59 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../includes/solong.h"

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

void	errormessage(void)
{
	write(1, "Error !\nNot Expected!", 21);
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

void	drawimgs(t_drgame *dr, char *i, int x, int y)
{
	int	width;
	int	height;

	dr->mlx.mlx_img = mlx_xpm_file_to_image(dr->mlx.mlx, i, &width, &height);
	if (!(dr->mlx.mlx_img))
		write(2, "IMG Error !", 12);
	mlx_put_image_to_window(dr->mlx.mlx, dr->mlx.win, dr->mlx.mlx_img, x, y);
}

void	initmap(t_drgame *drgame)
{
	int	init;

	while (drgame->y < ((drgame->linenum) * 40))
	{
		init = 0;
		while (init < drgame->lnchars)
		{
			if ((init + drgame->numb) < ft_strlen(drgame->map))
			{
				if (drgame->map[init + drgame->numb] != '1')
				{
					drgame->x += 40;
					drawmapitens(drgame, drgame->x, drgame->y, init);
				}
				else
					drawimgs(drgame, drgame->tree, drgame->x += 40, drgame->y);
			}
			init++;
		}
		drgame->x = -40;
		drgame->y += 40;
		drgame->numb += drgame->lnchars;
	}
}
