/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_gestionlist(t_tetri **tetralist, t_tetri *tetr, int cpt)
{
	tetr->next = NULL;
	tetr->prev = NULL;
	if (cpt == 0)
		return (tetr);
	else
	{
		ft_lstadend(tetralist, tetr);
		return (*tetralist);
	}
}

void			ft_posinitetr(t_tetri *tetr)
{
	while (tetr->x[0] != 0 && tetr->x[1] != 0 && tetr->x[2] != 0
			&& tetr->x[3] != 0)
	{
		tetr->x[0] -= 1;
		tetr->x[1] -= 1;
		tetr->x[2] -= 1;
		tetr->x[3] -= 1;
	}
	while (tetr->y[0] != 0 && tetr->y[1] != 0 && tetr->y[2] != 0
			&& tetr->y[3] != 0)
	{
		tetr->y[0] -= 1;
		tetr->y[1] -= 1;
		tetr->y[2] -= 1;
		tetr->y[3] -= 1;
	}
}

void			ft_creationlist(t_tetri **tetralist, char *buf, int cpt)
{
	t_tetri	*tetr;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	tetr = (t_tetri*)malloc(sizeof(t_tetri));
	tetr->order = 'A' + cpt;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			tetr->x[tmp] = i % 5;
			tetr->y[tmp] = j;
			tmp += 1;
		}
		if (buf[i] == '\n')
			j += 1;
		i += 1;
	}
	tetr->pos = 0;
	ft_posinitetr(tetr);
	*tetralist = ft_gestionlist(tetralist, tetr, cpt);
}
