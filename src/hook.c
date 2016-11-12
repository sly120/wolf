/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:05:09 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 20:48:39 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int		turn(int x, int y, t_param *p)
{
	double		rotation;

	if (x - p->mousex < 0)
		rotation = p->rotspeed;
	else
		rotation = -p->rotspeed;
	p->mousex = x;
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(rotation) - p->diry * sin(rotation);
	p->diry = p->olddirx * sin(rotation) + p->diry * cos(rotation);
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(rotation) - p->planey * sin(rotation);
	p->planey = p->oldplanex * sin(rotation) + p->planey * cos(rotation);
	raycasting(p);
	return (0);
}

static void		display_legend(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 0, 0, 0x0000FFFF, "w: move forward");
	mlx_string_put(p->mlx, p->win, 0, 15, 0x0000FFFF, "s: move backward");
	mlx_string_put(p->mlx, p->win, 0, 30, 0x0000FFFF, "a: move left");
	mlx_string_put(p->mlx, p->win, 0, 45, 0x0000FFFF, "d: move right");
	mlx_string_put(p->mlx, p->win, 170, 0, 0x0000FFFF, "shift: duck");
	mlx_string_put(p->mlx, p->win, 170, 15, 0x0000FFFF, "ctrl: run/walk");
	mlx_string_put(p->mlx, p->win, 170, 30, 0x0000FFFF, "enter: change light");
	mlx_string_put(p->mlx, p->win, 170, 45, 0x0000FFFF, "space: hide legend");
}

void			hook(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	p->legend ? display_legend(p) : mlx_string_put(p->mlx, p->win, 0, 0,
			0x0000FFFF, "legend : space");
	mlx_hook(p->win, 2, 1, key_event, p);
	mlx_hook(p->win, 17, 17, quit_program, p);
	mlx_hook(p->win, MOTIONNOTIFY, POINTERMOTIONMASK, turn, p);
	mlx_loop(p->mlx);
}
