/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:03:42 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:03:46 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	dr->mlx.win = mlx_new_window(dr->mlx.mlx, dr->width, dr->height, "DIE");
	dr->player = "./img/char.xpm";
	dr->exit = "./img/door.xpm";
	dr->sword = "./img/collect.xpm";
	dr->tree = "./img/block.xpm";
	dr->ground = "./img/ground.xpm";
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
	mlx_key_hook(drgame.mlx.win, key_hook, &drgame);
	mlx_hook(drgame.mlx.win, 15, 1L << 16, windowsize, &drgame);
	mlx_hook(drgame.mlx.win, 33, 1L << 5, exitgame, &drgame);
	mlx_loop(drgame.mlx.mlx);
}
