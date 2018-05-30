/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_verif(t_info *m, t_tetri *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((tmp->pos / m->sizem + tmp->y[i] >= m->sizem)
				|| (tmp->pos % m->sizem + tmp->x[i] >= m->sizem))
			return (0);
		if (m->map[tmp->pos / m->sizem + tmp->y[i]]
				[tmp->pos % m->sizem + tmp->x[i]] != '.')
			return (0);
		i += 1;
	}
	return (1);
}

static	int	ft_backt(t_info *m, t_tetri *tmp)
{
	if (m->nbt == 0)
		return (1);
	tmp->pos = 0;
	while (tmp->pos <= (m->sizem * m->sizem))
	{
		if (ft_verif(m, tmp))
		{
			ft_write(m, tmp);
			m->nbt--;
			if (ft_backt(m, tmp->next))
				return (1);
			ft_writeoff(m, tmp);
			m->nbt++;
		}
		tmp->pos++;
	}
	return (0);
}

void		ft_algo(t_info *m, t_tetri **tlst)
{
	int		i;

	m->pos = 0;
	while (!(ft_backt(m, *tlst)))
	{
		i = 0;
		while (i <= m->sizem)
		{
			free(m->map[i]);
			i += 1;
		}
		free(m->map);
		m->sizem += 1;
		m->map = ft_mapalloc(m->sizem);
	}
	ft_affichemap(m->map);
	i = 0;
	while (i <= m->sizem)
	{
		free(m->map[i]);
		i += 1;
	}
	free(m->map);
}
