/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_tetri{
	int				x[4];
	int				y[4];
	char			order;
	struct s_tetri	*next;
	struct s_tetri	*prev;
	int				pos;
}				t_tetri;

typedef	struct	s_info{
	int		nbt;
	int		x;
	int		y;
	char	**map;
	int		sizem;
	int		pos;
}				t_info;

void			ft_error(void);
int				ft_count(int nbchar);
int				ft_test(char const *str, int p, int s, int i);
int				ft_check2(char **tab);
void			ft_lstadend(t_tetri **tetralist, t_tetri *n);
void			ft_lstchangepos(t_tetri **alst, t_tetri *src, int pos);
void			ft_creationlist(t_tetri **tetralist, char *buf, int cpt);
int				ft_mapsize(char *s, t_info *info);
void			ft_affichemap(char **map);
char			**ft_mapalloc(int nb);
void			ft_gestionmap(char *s, t_tetri **tetralist, t_info *info);
void			ft_algo(t_info *m, t_tetri **tlst);
void			ft_posinitetr(t_tetri *tetr);
void			ft_write(t_info *m, t_tetri *tmp);
void			ft_writeoff(t_info *m, t_tetri *tmp);

#endif
