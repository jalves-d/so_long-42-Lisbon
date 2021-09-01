/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:11:14 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/01 15:34:35 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(char *s)
{
	int		i;
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tab = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		tab[i] = s2[j];
		i++;
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}
