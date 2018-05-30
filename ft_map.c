/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_mapalloc(int nb)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * nb + 1);
	while (i <= nb)
	{
		map[i] = (char *)malloc(sizeof(char) * nb + 1);
		i += 1;
	}
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			map[i][j] = '.';
			j += 1;
		}
		map[i][j] = '\0';
		i += 1;
	}
	map[i] = 0;
	return (map);
}

void		ft_affichemap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}

static int	ft_size(int d, int p)
{
	if (p * p >= d)
		return (p);
	return (ft_size(d, p + 1));
}

int			ft_mapsize(char *s, t_info *info)
{
	int i;
	int d;
	int p;

	i = 0;
	d = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == '#')
			d += 1;
		i += 1;
	}
	info->nbt = d / 4;
	p = ft_size(d, p);
	return (p);
}

void		ft_gestionmap(char *s, t_tetri **tetralist, t_info *m)
{
	int		i;
	t_tetri	*tmp;
	t_tetri *next;

	i = 0;
	tmp = *tetralist;
	m->sizem = ft_mapsize(s, m);
	if ((!(m->map = ft_mapalloc(m->sizem))))
		ft_error();
	ft_algo(m, tetralist);
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(tetralist);
}
