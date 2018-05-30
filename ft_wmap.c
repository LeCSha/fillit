/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_write(t_info *m, t_tetri *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		m->map[tmp->pos / m->sizem + tmp->y[i]][tmp->pos % m->sizem +
			tmp->x[i]] = tmp->order;
		i += 1;
	}
}

void	ft_writeoff(t_info *m, t_tetri *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		m->map[tmp->pos / m->sizem + tmp->y[i]][tmp->pos % m->sizem +
			tmp->x[i]] = '.';
		i += 1;
	}
}
