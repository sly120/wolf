/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:51:18 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:38:39 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void		mlx_initialization(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, MAX_X, MAX_Y, "Wolf3D");
	p->img = mlx_new_image(p->mlx, MAX_X, MAX_Y);
	p->imgad = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	if (p->bpp != 32 || p->endian != 0)
	{
		ft_putendl_fd("This program doesn't work on this computer\n", 2);
		exit(1);
	}
}

int				main(int argc, char **argv)
{
	t_param		p;

	mlx_initialization(&p);
	p.option = (argc == 1) ? 0 : 1;
	p.map = (p.option) ? readfile(&p, "./map/map2.txt") :
		readfile(&p, "./map/map.txt");
	wolf(&p);
	return (0);
}
