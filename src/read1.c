/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:25:59 by sly               #+#    #+#             */
/*   Updated: 2016/10/27 16:57:00 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int		ft_isspace_tab(int c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == 32);
}

static void		getstatstr(char *mapstr, t_param *i)
{
	int			x;

	i->tablenx = -1;
	i->tableny = 0;
	x = 0;
	while (*mapstr)
	{
		ft_isdigit(*mapstr) || *mapstr == '-' ? x++ : 0;
		while (ft_isdigit(*mapstr) || *mapstr == '-')
			mapstr++;
		if (*mapstr == '\n')
		{
			if (i->tablenx == -1)
				i->tablenx = x;
			else if (x != i->tablenx)
				exit(1);
			x = 0;
			i->tableny++;
			mapstr++;
		}
		if (*mapstr)
			while (ft_isspace_tab(*mapstr))
				mapstr++;
	}
	(*(mapstr - 1) != '\n') ? exit(1) : 0;
}

static int		ft_strlensp(char *s)
{
	return (*s && !(ft_isspace(*s)) && *s != '\n' ? ft_strlensp(++s) + 1 : 0);
}

static void		strtointab(char *mapstr, int ***tb, t_param *param)
{
	int			x;
	int			y;
	int			len;

	y = 0;
	x = 0;
	len = -1;
	while (*mapstr)
	{
		while (ft_isspace_tab(*mapstr))
			mapstr++;
		if (*mapstr)
		{
			if (*mapstr == '\n')
			{
				len == -1 ? len = x : 0;
				len != -1 && len != x ? exit(1) : 0;
				x = 0;
				y++;
				mapstr++;
			}
			*mapstr ? (*tb)[y][x++] = atoi(mapstr) : 0;
		}
		mapstr += ft_strlensp(mapstr);
	}
}

int				**readfile(t_param *param, char *src)
{
	char		*mapstr;
	int			**tb;
	int			i;

	i = open_file(src);
	mapstr = copy_src(src, i);
	getstatstr(mapstr, param);
	tb = createtab(param);
	strtointab(mapstr, &tb, param);
	free(mapstr);
	return (tb);
}
