/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadend(t_tetri **tetralist, t_tetri *n)
{
	t_tetri *tmp;

	tmp = NULL;
	if (n == NULL || tetralist == NULL)
		exit(0);
	n->next = NULL;
	n->prev = NULL;
	tmp = *tetralist;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = n;
	n->prev = tmp;
}
