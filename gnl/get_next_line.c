/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:12:12 by jalves-d          #+#    #+#             */
/*   Updated: 2021/08/30 16:19:20 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int		checkchar(char *src, int c)
{
	unsigned int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_subnstr(char *save)
{
	int		i;
	char	*line;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char				*ft_subastr(char *save)
{
	int		i;
	int		j;
	char	*s;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1))))
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

int					get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save[1024];
	int			byteslidos;

	if (!line || read(fd, 0, 0) == -1 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	byteslidos = 1;
	while (byteslidos != 0 && checkchar(save[fd], '\n') == 0)
	{
		byteslidos = read(fd, buf, BUFFER_SIZE);
		if (byteslidos == -1)
		{
			free(buf);
			return (-1);
		}
		buf[byteslidos] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	*line = ft_subnstr(save[fd]);
	save[fd] = ft_subastr(save[fd]);
	return (byteslidos == 0 ? 0 : 1);
}
