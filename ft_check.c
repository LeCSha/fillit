/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int		ft_count(int nbchar)
{
	if (nbchar % 21 != 20)
		ft_error();
	return (1);
}

int		ft_test(char const *str, int p, int s, int i)
{
	while (i < 22)
	{
		if (i % 5 == 0 && str[i - 1] != '\n')
			ft_error();
		if (i == 1 && str[i - 1] == '\n')
			break ;
		if (str[i - 1] != '.' && str[i - 1] != '#' && str[i - 1] != '\n')
			break ;
		if (i % 5 != 0)
		{
			if (str[i - 1] == '.')
				p += 1;
			if (str[i - 1] == '#')
				s += 1;
			i += 1;
		}
		if (i % 5 == 0 && str[i - 1] == '\n')
			i += 1;
	}
	if (s != 4 || p != 12)
		ft_error();
	return (1);
}

int		ft_check2(char **tab)
{
	int x;
	int y;
	int count;

	y = 0;
	count = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#' && x < 3)
				tab[y][x + 1] == '#' ? (count += 1) : (count);
			if (tab[y][x] == '#' && y < 3)
				tab[y + 1][x] == '#' ? (count += 1) : (count);
			if (tab[y][x] == '#' && x > 0)
				tab[y][x - 1] == '#' ? (count += 1) : (count);
			if (tab[y][x] == '#' && y > 0)
				tab[y - 1][x] == '#' ? (count += 1) : (count);
			x += 1;
		}
		y += 1;
	}
	return (count);
}
