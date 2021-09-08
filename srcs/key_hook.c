/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:04:08 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:04:10 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	moved(int key, t_drgame	*drgame, int pos)
{
	if (key == D)
	{
		if (drgame->map[pos + 1] == 'E' && !havec(drgame))
		{
			drgame->map[pos + 1] = 'P';
			drgame->map[pos] = '0';
			ft_putnbr(drgame);
			exitgame(drgame);
		}
		else if (drgame->map[pos + 1] != '1')
		{
			if (drgame->map[pos + 1] != 'E')
			{
				drgame->map[pos] = '0';
				drgame->lastitem = drgame->map[pos + 1];
				drgame->map[pos + 1] = 'P';
				ft_putnbr(drgame);
			}
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
			ft_putnbr(drgame);
			exitgame(drgame);
		}
		else if (drgame->map[pos - 1] != '1')
		{	
			if (drgame->map[pos - 1] != 'E')
			{
				drgame->map[pos] = '0';
				drgame->lastitem = drgame->map[pos - 1];
				drgame->map[pos - 1] = 'P';
				ft_putnbr(drgame);
			}
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
			ft_putnbr(dr);
			exitgame(dr);
		}
		else if (dr->map[pos + dr->lnchars] != '1')
		{	
			if (dr->map[pos + dr->lnchars] != 'E')
			{
				dr->map[pos] = '0';
				dr->lastitem = dr->map[pos + dr->lnchars];
				dr->map[pos + dr->lnchars] = 'P';
				ft_putnbr(dr);
			}
		}
	}
	else
		movea(key, dr, pos);
}

void	movew(int pos, int key, t_drgame *dr)
{
	while (dr->map[pos] != 'P')
		pos++;
	if (key == W)
	{
		if (dr->map[pos - dr->lnchars] == 'E' && !havec(dr))
		{
			dr->map[pos - dr->lnchars] = 'P';
			dr->map[pos] = '0';
			ft_putnbr(dr);
			exitgame(dr);
		}
		else if (dr->map[pos - dr->lnchars] != '1')
		{
			if (dr->map[pos - dr->lnchars] != 'E')
			{
				dr->map[pos] = '0';
				dr->lastitem = dr->map[pos - dr->lnchars];
				dr->map[pos - dr->lnchars] = 'P';
				ft_putnbr(dr);
			}
		}
	}
	else
		moves(key, dr, pos);
}

int	key_hook(int key, t_drgame *dr)
{
	char	*i;
	int		pos;

	pos = 0;
	if (key == ESC)
		exitgame(dr);
	if (key == W || key == S || key == A || key == D)
		movew(pos, key, dr);
	mlx_destroy_image(dr->mlx.mlx, dr->mlx.mlx_img);
	dr->mlx.mlx_img = mlx_new_image(dr->mlx.mlx, dr->width, dr->height);
	dr->y = 0;
	dr->x = -40;
	dr->numb = 0;
	dr->addr = NULL;
	initmap(dr);
	i = ft_itoa(dr->move);
	mlx_string_put(dr->mlx.mlx, dr->mlx.win, 10, 10, 0xFFFFFF, i);
	free(i);
	return (1);
}
