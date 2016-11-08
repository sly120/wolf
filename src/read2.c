/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:26:10 by sly               #+#    #+#             */
/*   Updated: 2016/10/27 16:58:05 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				open_file(char *file)
{
	int			fd;
	int			ret;
	int			total;
	char		c;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	total = 0;
	ret = 1;
	while (ret)
	{
		if ((ret = read(fd, &c, 1)) == -1)
			exit(1);
		if (!(ft_isdigit(c) || c == '\n' || c == '\0' || c == '-' || c == ' '))
			exit(1);
		total++;
	}
	close(fd);
	return (total);
}

char			*copy_src(char *src, int size)
{
	char		*mapstr;
	int			fd;

	if ((fd = open(src, O_RDONLY)) == -1)
		exit(1);
	if (!(mapstr = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	read(fd, mapstr, size);
	mapstr[size] = '\0';
	close(fd);
	return (mapstr);
}

int				**createtab(t_param *p)
{
	int			y;
	int			**tab;

	if (!(tab = (int**)malloc(sizeof(int*) * p->tableny)))
		exit(1);
	y = 0;
	while (y < p->tableny)
		if (!(tab[y++] = (int*)malloc(sizeof(int) * p->tablenx)))
			exit(1);
	return (tab);
}
