#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	void	*mlx_img;

}	t_mlx;

typedef struct s_drgame
{
	t_mlx	mlx;
	int		width;
	int		height;
	int		move;
	int 	bpp;
	char	*addr;
	char	*ground;
	char	*player;
	char	*sword;
	char	*tree;
	char	*exit;
	char	*map;
	int 	lastitem;
	int		lnchars;
	int		linenum;
	char	*player_position;
	int		numexit;
	int		numb;
	int		endl;
	int		fd;
	int		x;
	int		y;
}				t_drgame;

# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

int	havec(t_drgame *drgame);
void	solong(int argc, char **argv, t_drgame *drgame);
void	drgamedatas(t_drgame *dr);
int	windowsize(t_drgame *drgame);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strcat(char *dest, const char *src);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int	exitgame(t_drgame *drgame);
void	moved(int key, t_drgame	*drgame, int pos);
void	movea(int key, t_drgame	*drgame, int pos);
void	movew(int key, t_drgame *dr);
void	moves(int key, t_drgame *dr, int pos);
int	key_hook(int key, t_drgame *drgame);
void	errormessage();
void	drawmapitens(t_drgame *drgame, int x, int y, int z);
void	drawimgs(t_drgame *drgame, char *imgname, int x, int y);
void	initmap(t_drgame *drgame);
void	validmapitens(char *mapchars);
void	validmaps(t_drgame *drgame, char *mapchars);
void	validmap(char *map, t_drgame *drgame);
void	validotherwalls(t_drgame *drgame, char *line, int vergnl, char *mapchars);
void	validwalls(char *line);

#endif
