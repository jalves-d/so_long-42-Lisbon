/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:04:19 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:04:30 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../includes/solong.h"

static size_t	ft_len(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_signal(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = ft_len(n);
	str = (char *)malloc(i + 1);
	if (!(str))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		k = 1;
	}
	else
		k = 0;
	while (i > k)
	{
		i--;
		str[i] = '0' + n % 10 * ft_signal(n);
		n = n / 10;
	}
	return (str);
}

void	ft_putnbr(t_drgame *drgame)
{
	drgame->move++;
	ft_putnbr_fd(drgame->move, 1);
	write(1, "\n", 1);
}

int	checkendl(t_drgame *drgame)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(drgame->map);
	while (i < drgame->lnchars)
	{
		if (drgame->map[j - drgame->lnchars + i - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
