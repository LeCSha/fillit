/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:49:45 by abaille           #+#    #+#             */
/*   Updated: 2017/12/19 11:49:51 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_verif_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		exit(1);
	}
	return ;
}

static char		*ft_read_while(char *s, char *buf, char *tmp)
{
	int i;
	int j;
	int p;
	int k;

	j = 0;
	p = 0;
	k = 1;
	if (ft_test(buf, j, p, k) == 0)
		ft_error();
	i = ft_check2(ft_strsplit(buf, '\n'));
	if (i != 6 && i != 8)
		ft_error();
	tmp = ft_strdup(s);
	free(s);
	s = ft_strjoin(tmp, buf);
	free(tmp);
	tmp = NULL;
	return (s);
}

static void		ft_troplong(int fd)
{
	if (fd == -1)
		ft_error();
}

static char		*ft_read(char *s, char *buf, int fd, t_tetri **tetralist)
{
	char	*tmp;
	int		ret;
	int		cpt;
	int		nbchar;

	cpt = 0;
	nbchar = 0;
	ft_troplong(fd);
	if (!(s = ft_strnew(1)))
		ft_error();
	s[0] = '\0';
	tmp = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		s = ft_read_while(s, buf, tmp);
		ft_creationlist(tetralist, buf, cpt);
		cpt++;
		nbchar += ret;
		if (cpt > 26)
			ft_error();
	}
	if (!(ft_count(nbchar)))
		ft_error();
	return (s);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	buf[22];
	char	*s;
	t_tetri **tetralist;
	t_info	*m;

	tetralist = NULL;
	m = NULL;
	if ((tetralist = (t_tetri**)malloc(sizeof(t_tetri *))) == NULL)
		exit(0);
	if ((m = (t_info*)malloc(sizeof(t_info))) == NULL)
		exit(0);
	s = NULL;
	ft_verif_argc(argc);
	fd = open(argv[1], O_RDONLY);
	if (!(s = ft_read(s, buf, fd, tetralist)))
		ft_error();
	if (close(fd) == -1)
		ft_error();
	m->x = 0;
	m->y = 0;
	fd = 0;
	ft_gestionmap(s, tetralist, m);
	return (0);
}
