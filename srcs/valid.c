#include "../includes/solong.h"

void	validmapitens(char *mapchars)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (mapchars[i])
	{
		if (mapchars[i] == 'P')
			player++;
		if ((mapchars[i] != '1') && (mapchars[i] != '0') && (mapchars[i] != 'E'))
			if (mapchars[i] != 'P' && mapchars[i] != 'C')
			{
				free(mapchars);
				errormessage();
			}
		i++;
	}
	if (player > 1)
		errormessage();
}

void	validmaps(t_drgame *drgame, char *mapchars)
{
	if (!(ft_strchr(mapchars, 'P')) || !(ft_strchr(mapchars, 'E')))
		errormessage();
	if (drgame->linenum - 1 == drgame->lnchars || !(ft_strchr(mapchars, 'C')))
		errormessage();
	validmapitens(mapchars);
	drgame->numexit = 0;
	drgame->move = 0;
	drgame->height = (drgame->linenum - 1) * 40;
	drgame->width = drgame->lnchars * 40;
	drgame->map = malloc(sizeof(char) * (drgame->lnchars * drgame->linenum) + 1);
	ft_strlcpy(drgame->map, mapchars, (drgame->linenum * drgame->lnchars));
	drgame->fd = close(drgame->fd);
	free(mapchars);
}

void	validotherwalls(t_drgame *drgame, char *line, int vergnl, char *mapchars)
{
	while (vergnl > 0)
	{
		drgame->endl = ft_strlen(line) - 1;
		if (line[0] != '1' || line[drgame->endl] != '1' || ((vergnl != 0) && (ft_strlen(line) != drgame->lnchars)))
			errormessage();
		ft_strcat(mapchars, line);
		free(line);
		line = 0;
		vergnl = get_next_line(drgame->fd, &line);
		drgame->linenum++;
		if (vergnl == 0)
		{
			validwalls(line);
			ft_strcat(mapchars, line);
			free(line);
			line = 0;
			drgame->linenum++;
		}
	}
}

void	validwalls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			free(line);
			errormessage();
		}
		i++;
	}
}

void	validmap(char *map, t_drgame *drgame)
{
	char	*line;
	int		vergnl;
	char	*mapchars;

	mapchars = malloc(sizeof(char *) * 10000);
	*mapchars = 0;
	line = 0;
	drgame->fd = open(map, O_RDONLY);
	drgame->linenum = 0;
	if (drgame->fd == -1)
		errormessage();
	vergnl = get_next_line(drgame->fd, &line);
	drgame->lnchars = ft_strlen(line);
	validwalls(line);
	validotherwalls(drgame, line, vergnl, mapchars);
	validmaps(drgame, mapchars);
	drgamedatas(drgame);
}
